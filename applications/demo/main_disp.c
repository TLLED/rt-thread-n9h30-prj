//#include "../../lv_demo.h"
//#include "lv_examples/src/lv_demo.h"
#include "lv_demo_widgets.h"

typedef enum {
    DISP_SMALL,
    DISP_MEDIUM,
    DISP_LARGE,
}disp_size_t;

static disp_size_t disp_size;

static lv_style_t style_title;
//static lv_style_t style_bullet;





static lv_style_t style_text_muted;
static lv_style_t style_title;
static lv_style_t style_icon;

static const lv_font_t * font_large;
static const lv_font_t * font_normal;


static lv_obj_t * panel1;
static lv_obj_t * name;
static lv_obj_t * status;
static lv_obj_t * sensor_pwr_btn_open;
static lv_obj_t * sensor_pwr_btn_close;
static lv_obj_t * label;

static lv_obj_t * panel2;
static lv_obj_t * panel2_title;
static lv_obj_t * can_rxdat_label;
static lv_obj_t * can_rxdat;
static lv_obj_t * can_par0;
static lv_obj_t * can_par1;
static lv_obj_t * can_par2;
static lv_obj_t * can_par3;
static lv_obj_t * can_par4;
static lv_obj_t * can_par5;
static lv_obj_t * can_par6;
static lv_obj_t * can_par7;

static lv_obj_t * panel4;
static lv_obj_t * panel4_title;
static lv_obj_t * motor_cur_label;
static lv_obj_t * motor_volt_label;
static lv_obj_t * motor_spd_label;

static lv_obj_t * panel5;
static lv_obj_t * panel5_title;
static lv_obj_t * motor_pwr_status;
static lv_obj_t * motor_pwr_btn_open;
static lv_obj_t * motor_pwr_btn_close;
static lv_obj_t * motor_label;



//pwr_open
static void sensor_pwr_open_btn_event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);

    if(code == LV_EVENT_CLICKED)
    {
        lv_label_set_recolor(status, true);
        lv_label_set_text_fmt(status, "#00ff00 Status:  device open!");
    }
}

//pwr_close
static void sensor_pwr_close_btn_event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);

    if(code == LV_EVENT_CLICKED)
    {
        lv_label_set_recolor(status, true);
        lv_label_set_text_fmt(status, "#ff0000 Status:  device close!");
    }
}

//motor_open
static void motor_pwr_open_btn_event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);

    if(code == LV_EVENT_CLICKED)
    {
        lv_label_set_recolor(motor_pwr_status, true);
        lv_label_set_text_fmt(motor_pwr_status, "#00ff00 Status:  motor open!");
    }
}
//motor_close
static void motor_pwr_close_btn_event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);

    if(code == LV_EVENT_CLICKED)
    {
        lv_label_set_recolor(motor_pwr_status, true);
        lv_label_set_text_fmt(motor_pwr_status, "#ff0000 Status:  motor close!");
    }
}


 void  main_disp_create(lv_obj_t * parent)
 {
    //panel1-------------------------------------------------------------------------------------------
    panel1 = lv_obj_create(parent);
    lv_obj_set_height(panel1, LV_SIZE_CONTENT);

    name = lv_label_create(panel1);
    lv_label_set_text(name, "Sensor power switch");
    lv_obj_add_style(name, &style_title, 0);

    status = lv_label_create(panel1);
    lv_label_set_recolor(status, true);
    lv_label_set_text(status, "#FF0000 Status:  device close!");
    lv_obj_add_style(status, &style_title, 0);

    sensor_pwr_btn_open = lv_btn_create(panel1);
    lv_obj_set_height(sensor_pwr_btn_open, LV_SIZE_CONTENT);
    lv_obj_add_event_cb(sensor_pwr_btn_open, sensor_pwr_open_btn_event_handler, LV_EVENT_ALL, NULL);

    label = lv_label_create(sensor_pwr_btn_open);
    lv_label_set_text(label, "Open");
    lv_obj_center(label);

    sensor_pwr_btn_close = lv_btn_create(panel1);
    lv_obj_set_height(sensor_pwr_btn_close, LV_SIZE_CONTENT);
    lv_obj_add_event_cb(sensor_pwr_btn_close, sensor_pwr_close_btn_event_handler, LV_EVENT_ALL, NULL);

    label = lv_label_create(sensor_pwr_btn_close);
    lv_label_set_text(label, "Close");
    lv_obj_center(label);

    //panel2-------------------------------------------------------------------------------------------
    panel2 = lv_obj_create(parent);
    lv_obj_set_height(panel2, LV_SIZE_CONTENT);

    panel2_title = lv_label_create(panel2);
    lv_label_set_text(panel2_title, "Can disp");
    lv_obj_add_style(panel2_title, &style_title, 0);

    can_rxdat_label = lv_label_create(panel2);
    lv_label_set_text(can_rxdat_label, "canrx:");
    lv_obj_add_style(can_rxdat_label, &style_title, 0);

    can_rxdat = lv_label_create(panel2);
    lv_label_set_text(can_rxdat, "00 01 02 03 04 05 06 07");
    lv_obj_add_style(can_rxdat, &style_title, 0);

    can_par0 = lv_label_create(panel2);
    lv_label_set_text(can_par0, "par1: xxm   ");
    lv_obj_add_style(can_par0, &style_title, 0);

    can_par1 = lv_label_create(panel2);
    lv_label_set_text(can_par1, "par2: xxm   ");
    lv_obj_add_style(can_par1, &style_title, 0);

    can_par2 = lv_label_create(panel2);
    lv_label_set_text(can_par2, "par3: xxm");
    lv_obj_add_style(can_par2, &style_title, 0);

    can_par3 = lv_label_create(panel2);
    lv_label_set_text(can_par3, "par4: xxm");
    lv_obj_add_style(can_par3, &style_title, 0);

    can_par4 = lv_label_create(panel2);
    lv_label_set_text(can_par4, "par5: xxm");
    lv_obj_add_style(can_par4, &style_title, 0);

    can_par5 = lv_label_create(panel2);
    lv_label_set_text(can_par5, "par6: xxm");
    lv_obj_add_style(can_par5, &style_title, 0);

    can_par6 = lv_label_create(panel2);
    lv_label_set_text(can_par6, "par7: xxm");
    lv_obj_add_style(can_par6, &style_title, 0);

    can_par7 = lv_label_create(panel2);
    lv_label_set_text(can_par7, "par8: xxm");
    lv_obj_add_style(can_par7, &style_title, 0);

    //panel4-------------------------------------------------------------------------------------------
    panel4 = lv_obj_create(parent);

    panel4_title = lv_label_create(panel4);
    lv_label_set_text(panel4_title, "Motor par");
    lv_obj_add_style(panel4_title, &style_title, 0);

    motor_cur_label = lv_label_create(panel4);
    lv_label_set_text(motor_cur_label, "Current -- 10A");
    lv_obj_add_style(motor_cur_label, &style_title, 0);

    motor_volt_label = lv_label_create(panel4);
    lv_label_set_text(motor_volt_label, "Voltage -- 220V");
    lv_obj_add_style(motor_volt_label, &style_title, 0);

    motor_spd_label = lv_label_create(panel4);
    lv_label_set_text(motor_spd_label, "Speed -- 100km/h");
    lv_obj_add_style(motor_spd_label, &style_title, 0);


    //panel5-------------------------------------------------------------------------------------------
    panel5 = lv_obj_create(parent);
    panel5_title = lv_label_create(panel5);
    lv_label_set_text(panel5_title, "Motor control");
    lv_obj_add_style(panel5_title, &style_title, 0);

    motor_pwr_status = lv_label_create(panel5);
    lv_label_set_recolor(motor_pwr_status, true);
    lv_label_set_text(motor_pwr_status, "#FF0000 Status:  motor close!");
    lv_obj_add_style(motor_pwr_status, &style_title, 0);

    motor_pwr_btn_open = lv_btn_create(panel5);
    lv_obj_set_height(motor_pwr_btn_open, LV_SIZE_CONTENT);
    lv_obj_add_event_cb(motor_pwr_btn_open, motor_pwr_open_btn_event_handler, LV_EVENT_ALL, NULL);

    motor_label = lv_label_create(motor_pwr_btn_open);
    lv_label_set_text(motor_label, "Open");
    lv_obj_center(motor_label);

    motor_pwr_btn_close = lv_btn_create(panel5);
    lv_obj_set_height(motor_pwr_btn_close, LV_SIZE_CONTENT);
    lv_obj_add_event_cb(motor_pwr_btn_close, motor_pwr_close_btn_event_handler, LV_EVENT_ALL, NULL);

    motor_label = lv_label_create(motor_pwr_btn_close);
    lv_label_set_text(motor_label, "Close");
    lv_obj_center(motor_label);



    static lv_coord_t grid_main_col_dsc[] = {LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
    static lv_coord_t grid_main_row_dsc[] = {LV_GRID_CONTENT, LV_GRID_CONTENT, LV_GRID_TEMPLATE_LAST};

    //Create the top panel
    static lv_coord_t grid_1_col_dsc[] = {LV_GRID_CONTENT, 5, LV_GRID_CONTENT, LV_GRID_FR(2), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
    static lv_coord_t grid_1_row_dsc[] = {LV_GRID_CONTENT, LV_GRID_CONTENT, 10, LV_GRID_CONTENT, LV_GRID_CONTENT, LV_GRID_TEMPLATE_LAST};

    static lv_coord_t grid_2_col_dsc[] = {LV_GRID_FR(1),  LV_GRID_TEMPLATE_LAST};
    static lv_coord_t grid_2_row_dsc[] = {
            LV_GRID_CONTENT,
            LV_GRID_CONTENT,
            LV_GRID_CONTENT,
            LV_GRID_CONTENT,
            LV_GRID_CONTENT,
            LV_GRID_CONTENT,
            LV_GRID_CONTENT,
            LV_GRID_CONTENT,
            LV_GRID_CONTENT,
            LV_GRID_TEMPLATE_LAST
    };

    lv_obj_set_grid_dsc_array(parent, grid_main_col_dsc, grid_main_row_dsc);

    lv_obj_set_grid_cell(panel1,        LV_GRID_ALIGN_STRETCH,  0, 3, LV_GRID_ALIGN_CENTER, 0, 1);
    lv_obj_set_grid_dsc_array(panel1, grid_1_col_dsc, grid_1_row_dsc);
    lv_obj_set_grid_cell(name,                  LV_GRID_ALIGN_START,    0, 1, LV_GRID_ALIGN_CENTER, 0, 1);
    lv_obj_set_grid_cell(status,                LV_GRID_ALIGN_STRETCH,  0, 1, LV_GRID_ALIGN_START,  1, 1);
    lv_obj_set_grid_cell(sensor_pwr_btn_open,   LV_GRID_ALIGN_STRETCH,  4, 1, LV_GRID_ALIGN_CENTER, 0, 2);
    lv_obj_set_grid_cell(sensor_pwr_btn_close,  LV_GRID_ALIGN_STRETCH,  5, 1, LV_GRID_ALIGN_CENTER, 0, 2);

    lv_obj_set_grid_cell(panel2,            LV_GRID_ALIGN_STRETCH,  0, 1, LV_GRID_ALIGN_STRETCH,  1, 1);
    lv_obj_set_grid_dsc_array(panel2, grid_2_col_dsc, grid_2_row_dsc);
    lv_obj_set_grid_cell(panel2_title,      LV_GRID_ALIGN_START,        0, 2, LV_GRID_ALIGN_CENTER, 0, 1);
    lv_obj_set_grid_cell(can_rxdat_label,   LV_GRID_ALIGN_STRETCH,      0, 1, LV_GRID_ALIGN_CENTER, 1, 1);
    lv_obj_set_grid_cell(can_rxdat,         LV_GRID_ALIGN_STRETCH,      0, 1, LV_GRID_ALIGN_START,  2, 1);
    lv_obj_set_grid_cell(can_par0,          LV_GRID_ALIGN_STRETCH,      0, 1, LV_GRID_ALIGN_START,  3, 1);
    lv_obj_set_grid_cell(can_par1,          LV_GRID_ALIGN_STRETCH,      0, 1, LV_GRID_ALIGN_START,  4, 1);
    lv_obj_set_grid_cell(can_par2,          LV_GRID_ALIGN_STRETCH,      0, 1, LV_GRID_ALIGN_START,  5, 1);
    lv_obj_set_grid_cell(can_par3,          LV_GRID_ALIGN_STRETCH,      0, 1, LV_GRID_ALIGN_START,  6, 1);
    lv_obj_set_grid_cell(can_par4,          LV_GRID_ALIGN_START,        4, 3, LV_GRID_ALIGN_START,  3, 1);
    lv_obj_set_grid_cell(can_par5,          LV_GRID_ALIGN_START,        4, 3, LV_GRID_ALIGN_START,  4, 1);
    lv_obj_set_grid_cell(can_par6,          LV_GRID_ALIGN_START,        4, 3, LV_GRID_ALIGN_START,  5, 1);
    lv_obj_set_grid_cell(can_par7,          LV_GRID_ALIGN_START,        4, 3, LV_GRID_ALIGN_START,  6, 1);

    lv_obj_set_grid_cell(panel4,            LV_GRID_ALIGN_STRETCH,      1, 1, LV_GRID_ALIGN_STRETCH, 1, 1);
    lv_obj_set_grid_dsc_array(panel4, grid_2_col_dsc, grid_2_row_dsc);
    lv_obj_set_grid_cell(panel4_title,      LV_GRID_ALIGN_START,        0, 2, LV_GRID_ALIGN_CENTER, 0, 1);
    lv_obj_set_grid_cell(motor_cur_label,   LV_GRID_ALIGN_START,        0, 1, LV_GRID_ALIGN_CENTER, 1, 1);
    lv_obj_set_grid_cell(motor_volt_label,  LV_GRID_ALIGN_START,        0, 1, LV_GRID_ALIGN_CENTER, 2, 1);
    lv_obj_set_grid_cell(motor_spd_label,   LV_GRID_ALIGN_START,        0, 1, LV_GRID_ALIGN_CENTER, 3, 1);

    lv_obj_set_grid_cell(panel5,            LV_GRID_ALIGN_STRETCH,      2, 1, LV_GRID_ALIGN_STRETCH, 1, 1);
    lv_obj_set_grid_dsc_array(panel5, grid_2_col_dsc, grid_2_row_dsc);
    lv_obj_set_grid_cell(panel5_title,      LV_GRID_ALIGN_START,        0, 2, LV_GRID_ALIGN_CENTER, 0, 1);
    lv_obj_set_grid_cell(motor_pwr_status,  LV_GRID_ALIGN_START,        0, 1, LV_GRID_ALIGN_CENTER, 1, 1);
    lv_obj_set_grid_cell(motor_pwr_btn_open,LV_GRID_ALIGN_START,        0, 2, LV_GRID_ALIGN_CENTER, 3, 1);
    lv_obj_set_grid_cell(motor_pwr_btn_close,LV_GRID_ALIGN_START,       0, 2, LV_GRID_ALIGN_CENTER, 6, 1);

 }



