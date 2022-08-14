
#ifndef MAIN_DISP_H
#define MAIN_DISP_H

#ifdef __cplusplus
extern "C" {
#endif

void main_disp_create(lv_obj_t * parent);
void main_motor_setvalue(uint8_t cr, uint8_t vt, uint8_t sp);
void main_canrx_setvalue(uint8_t *cx);
void main_canpar_setvalue(uint8_t *cp);



#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
