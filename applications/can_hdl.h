/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-08-13     hui       the first version
 */
#ifndef APPLICATIONS_CAN_HDL_H_
#define APPLICATIONS_CAN_HDL_H_

void can_txdat(uint32_t id, uint8_t *dat);
//int can_sample(int argc, char *argv[]);
int can_sample(void);


#endif /* APPLICATIONS_CAN_HDL_H_ */
