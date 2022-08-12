
#ifndef LD_DISP_H
#define LD_DISP_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

//#include "../lv_demo.h"
#include "lv_demo_widgets.h"

void  ld_disp_create(lv_obj_t * parent);

void chart_set_value( uint8_t se1, uint8_t se2, uint8_t se3, uint8_t se4);



#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
