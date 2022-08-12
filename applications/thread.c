
#include <rtconfig.h>
#include <rtdevice.h>
#include "ld_disp.h"

struct rt_mailbox canrx_spline_rxmb;
static uint8_t canrx_spline_rxmb_pool[20];

rt_uint8_t canrx_spline_buf[10];



static void canrx_spline_thread_entry(void)
{
    uint16_t t1=50;
    uint16_t t2=100;
    uint16_t t3=150;
    uint16_t t4=200;

    while(1)
    {
        t1++;
        if(t1>255)
        {
           t1=0;
        }

        t2++;
        if(t2>255)
        {
           t2=0;
        }
        t3++;
        if(t3>255)
        {
           t3=0;
        }
        t4++;
        if(t4>255)
        {
           t4=0;
        }
        canrx_spline_buf[0]=t1;
        canrx_spline_buf[1]=t2;
        canrx_spline_buf[2]=t3;
        canrx_spline_buf[3]=t4;
        rt_mb_send(&canrx_spline_rxmb, (rt_uint32_t)&canrx_spline_buf);
        rt_kprintf("canrx_spline_thread! \n");

        rt_thread_delay(200);
    }
}

static void canrx_main_thread_entry(void)
{
    rt_uint8_t *str;
    rt_uint8_t temp[5];

    while(1)
    {
        if (rt_mb_recv(&canrx_spline_rxmb, (rt_uint32_t *)&str, RT_WAITING_NO) == RT_EOK)
        {
           temp[0]=str[0];
           temp[1]=str[1];
           temp[2]=str[2];
           temp[3]=str[3];


           chart_set_value( temp[0], temp[1], temp[2], temp[3]);

           rt_kprintf("rx:%x, %x, %x, %x \n",str[0],str[1],str[2],str[3]);
        }
        rt_kprintf("canrx_main_thread! \n");
        rt_thread_delay(100);
    }
}


int thread_init(void)
{
    static rt_thread_t thread_id = RT_NULL;
    rt_err_t result;
    rt_err_t ret = RT_EOK;

    /* 初 始 化 一 个 mailbox */
    result = rt_mb_init(&canrx_spline_rxmb,
                        "canrx_spline_rxmbt",
                        &canrx_spline_rxmb_pool[0], /* 邮 箱 用 到 的 内 存 池 是 mb_pool */
                        sizeof(canrx_spline_rxmb_pool) / 4, /* 邮 箱 中 的 邮 件 数 目， 因 为 一 封 邮件 占 4 字 节 */
                        RT_IPC_FLAG_FIFO); /* 采 用 FIFO 方 式 进 行 线 程 等 待 */
    if (result != RT_EOK)
    {
        rt_kprintf("init canrx_spline mailbox failed.\n");
        return -1;
    }




    //thread1
    thread_id = rt_thread_create("gui_spline",    //名称
                                     canrx_spline_thread_entry,   //线程代码
                                     RT_NULL,         //参数
                                     1024,            //栈大小
                                     2,              //优先级
                                     20);             //时间片

        if (thread_id != RT_NULL)
            rt_thread_startup(thread_id);             //线程进入就绪态
        else
            rt_kprintf("gui_spline thread create failure\n");
    //thread2
    thread_id = rt_thread_create("gui_main",    //名称
                                  canrx_main_thread_entry,  //线程代码
                                  RT_NULL,        //参数
                                  1024,           //栈大小
                                  3,             //优先级
                                  20);            //时间片
    if (thread_id != RT_NULL)
       rt_thread_startup(thread_id);              //线程进入就绪态
    else
       rt_kprintf("gui_main thread create failure\n");

    return RT_EOK;

}

//INIT_APP_EXPORT(thread_init);
