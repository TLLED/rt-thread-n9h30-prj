/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2019-06-25     misonyo      first implementation.
 */
/*
 * �����嵥������һ�� CAN �豸ʹ������
 * ���̵����� can_sample ��������ն�
 * ������ø�ʽ��can_sample can2
 * ������ͣ�����ڶ���������Ҫʹ�õ� CAN �豸���ƣ�Ϊ����ʹ��Ĭ�ϵ� CAN �豸
 * �����ܣ�ͨ�� CAN �豸����һ֡��������һ���߳̽�������Ȼ���ӡ�����
*/

#include <rtthread.h>
#include "rtdevice.h"
#include "thread.h"

#define CAN_DEV_NAME       "can0"      /* CAN �豸���� */

static struct rt_semaphore rx_sem;     /* ���ڽ�����Ϣ���ź��� */
static rt_device_t can_dev;            /* CAN �豸��� */

/* �������ݻص����� */
static rt_err_t can_rx_call(rt_device_t dev, rt_size_t size)
{
    /* CAN ���յ����ݺ�����жϣ����ô˻ص�������Ȼ���ͽ����ź��� */
    rt_sem_release(&rx_sem);

    return RT_EOK;
}

static void can_rx_thread(void *parameter)
{
    int i;
    rt_err_t res;
    struct rt_can_msg rxmsg = {0};
    uint8_t can_rxdat[10];

    /* ���ý��ջص����� */
    rt_device_set_rx_indicate(can_dev, can_rx_call);

#ifdef RT_CAN_USING_HDR
    struct rt_can_filter_item items[5] =
    {
        RT_CAN_FILTER_ITEM_INIT(0x100, 0, 0, 0, 0x700, RT_NULL, RT_NULL), /* std,match ID:0x100~0x1ff��hdrΪ-1������Ĭ�Ϲ��˱� */
        RT_CAN_FILTER_ITEM_INIT(0x300, 0, 0, 0, 0x700, RT_NULL, RT_NULL), /* std,match ID:0x300~0x3ff��hdrΪ-1 */
        RT_CAN_FILTER_ITEM_INIT(0x211, 0, 0, 0, 0x7ff, RT_NULL, RT_NULL), /* std,match ID:0x211��hdrΪ-1 */
        RT_CAN_FILTER_STD_INIT(0x486, RT_NULL, RT_NULL),                  /* std,match ID:0x486��hdrΪ-1 */
        {0x555, 0, 0, 0, 0x7ff, 7,}                                       /* std,match ID:0x555��hdrΪ7��ָ������7�Ź��˱� */
    };
    struct rt_can_filter_config cfg = {5, 1, items}; /* һ����5�����˱� */
    /* ����Ӳ�����˱� */
    res = rt_device_control(can_dev, RT_CAN_CMD_SET_FILTER, &cfg);
    RT_ASSERT(res == RT_EOK);
#endif

    while (1)
    {
        /* hdrֵΪ-1����ʾֱ�Ӵ�uselist������ȡ���� */
        rxmsg.hdr = -1;
        /* �����ȴ������ź��� */
        rt_sem_take(&rx_sem, RT_WAITING_FOREVER);
        /* ��CAN��ȡһ֡���� */
        rt_device_read(can_dev, 0, &rxmsg, sizeof(rxmsg));
        /* ��ӡ����ID������ */
        //rt_kprintf("ID:%x  ", rxmsg.id);
        for (i = 0; i < 8; i++)
        {
            //rt_kprintf("%2x ", rxmsg.data[i]);
            can_rxdat[i]=rxmsg.data[i];
        }

        can_rxdat[9]=rxmsg.id;

        rt_mb_send(&canrx_spline_rxmb, (rt_uint32_t)&can_rxdat);
        //rt_kprintf("\n");
    }
}

//int can_sample(int argc, char *argv[])
int can_sample(void)
{
    struct rt_can_msg msg = {0};
    rt_err_t res;
    rt_size_t  size;
    rt_thread_t thread;
    char can_name[RT_NAME_MAX];
    
    rt_strncpy(can_name, CAN_DEV_NAME, RT_NAME_MAX);

   /* if (argc == 2)
    {
        rt_strncpy(can_name, argv[1], RT_NAME_MAX);
    }
    else
    {
        rt_strncpy(can_name, CAN_DEV_NAME, RT_NAME_MAX);
    }
*/
    can_dev = rt_device_find(can_name);
    if (!can_dev)
    {
        rt_kprintf("find %s failed!\n", can_name);
        return RT_ERROR;
    }

    /* ��ʼ��CAN�����ź��� */
    rt_sem_init(&rx_sem, "rx_sem", 0, RT_IPC_FLAG_FIFO);

    /* ���жϽ��ռ����ͷ�ʽ��CAN�豸 */
    res = rt_device_open(can_dev,  RT_DEVICE_FLAG_INT_TX | RT_DEVICE_FLAG_INT_RX); //
    RT_ASSERT(res == RT_EOK);

    res = rt_device_control(can_dev, RT_CAN_CMD_SET_BAUD, (void *)CAN100kBaud);
    RT_ASSERT(res == RT_EOK);
    res = rt_device_control(can_dev, RT_CAN_CMD_SET_MODE, (void *)RT_CAN_MODE_NORMAL);

    thread = rt_thread_create("can_rx", can_rx_thread, RT_NULL, 1024, 25, 10);
    if (thread != RT_NULL)
    {
        rt_thread_startup(thread);
    }
    else
    {
        rt_kprintf("create can_rx thread failed!\n");
    }

    msg.id = 0x200515;
    msg.ide = RT_CAN_EXTID;//RT_CAN_STDID;
    msg.rtr = RT_CAN_DTR;
    msg.len = 8;

    msg.data[0] = 0x00;
    msg.data[1] = 0x11;
    msg.data[2] = 0x22;
    msg.data[3] = 0x33;
    msg.data[4] = 0x44;
    msg.data[5] = 0x55;
    msg.data[6] = 0x66;
    msg.data[7] = 0x77;

    size = rt_device_write(can_dev, 0, &msg, sizeof(msg));
    if (size == 0)
    {
        rt_kprintf("can dev write data failed!\n");
    }

    return res;
}


void can_txdat(uint32_t id, uint8_t *dat)
{
    rt_err_t res;
    rt_size_t  size;
    struct rt_can_msg msg = {0};
    msg.id = id;
    msg.ide = RT_CAN_EXTID;//RT_CAN_STDID;
    msg.rtr = RT_CAN_DTR;
    msg.len = 8;

    msg.data[0] = dat[0];
    msg.data[1] = dat[1];
    msg.data[2] = dat[2];
    msg.data[3] = dat[3];
    msg.data[4] = dat[4];
    msg.data[5] = dat[5];
    msg.data[6] = dat[6];
    msg.data[7] = dat[7];
    size = rt_device_write(can_dev, 0, &msg, sizeof(msg));
    if (size == 0)
    {
        rt_kprintf("can dev write data failed!\n");
    }

}
/* ������ msh �����б��� */
MSH_CMD_EXPORT(can_sample, can device sample);