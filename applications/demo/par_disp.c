//#include "../../lv_demo.h"
//#include "lv_examples/src/lv_demo.h"
#include "lv_demo_widgets.h"
#include "can_hdl.h"

static lv_style_t style_title;
static lv_style_t style_bullet;

static lv_obj_t * meter1;
static lv_obj_t * meter2;
static lv_obj_t * meter3;

static lv_obj_t * par1;
static lv_obj_t * volt;
static lv_obj_t * spd;

static lv_obj_t * motor_sw;
static lv_obj_t * motor_title;

static lv_obj_t * motor_pr_status;
static lv_obj_t * motor_pr_btn_open;
static lv_obj_t * motor_pr_btn_close;
static lv_obj_t * motor_label;
static lv_obj_t * motor_status;

static lv_obj_t * cur_val_label;
static lv_obj_t * volt_val_label;
static lv_obj_t * spd_val_label;

static lv_meter_scale_t * scale;

static lv_meter_indicator_t *cur_indic;
static lv_meter_indicator_t *volt_indic;
static lv_meter_indicator_t *spd_indic;

uint8_t ptxdat[8]={0,0,0,0,0,0,0,0};

//motor_open
static void motor_pr_open_btn_event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);

    if(code == LV_EVENT_CLICKED)
    {
        lv_label_set_recolor(motor_status, true);
        lv_label_set_text_fmt(motor_status, "#00ff00 Status:  motor open!");
        ptxdat[7]=0x01;
        can_txdat(0x200611, ptxdat);
    }
}
//motor_close
static void motor_pr_close_btn_event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);

    if(code == LV_EVENT_CLICKED)
    {
        lv_label_set_recolor(motor_status, true);
        lv_label_set_text_fmt(motor_status, "#ff0000 Status:  motor close!");
        ptxdat[7]=0x00;
        can_txdat(0x200611, ptxdat);
    }
}


static lv_obj_t * meter_box(lv_obj_t * parent, const char * title, const char * text1)
{
    lv_obj_t * cont = lv_obj_create(parent);
    lv_obj_set_height(cont, LV_SIZE_CONTENT);
    lv_obj_set_flex_grow(cont, 1);

    lv_obj_t * title_label = lv_label_create(cont);
    lv_label_set_text(title_label, title);
    lv_obj_add_style(title_label, &style_title, 0);

    lv_obj_t * meter = lv_meter_create(cont);
    lv_obj_remove_style(meter, NULL, LV_PART_MAIN);
    lv_obj_remove_style(meter, NULL, LV_PART_INDICATOR);
    lv_obj_set_width(meter, LV_PCT(100));

   /* lv_obj_t * bullet1 = lv_obj_create(cont);
    lv_obj_set_size(bullet1, 13, 13);
    lv_obj_remove_style(bullet1, NULL, LV_PART_SCROLLBAR);
    lv_obj_add_style(bullet1, &style_bullet, 0);
    lv_obj_set_style_bg_color(bullet1, lv_palette_main(LV_PALETTE_RED), 0);
    lv_obj_t * label1 = lv_label_create(cont);
    lv_label_set_text(label1, text1);*/


    //static lv_coord_t grid_col_dsc[] = {LV_GRID_CONTENT, LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
    //static lv_coord_t grid_row_dsc[] = {LV_GRID_CONTENT, LV_GRID_CONTENT, LV_GRID_CONTENT, LV_GRID_TEMPLATE_LAST};
    static lv_coord_t grid_col_dsc[] = {LV_GRID_CONTENT, LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
    static lv_coord_t grid_row_dsc[] = {LV_GRID_CONTENT, LV_GRID_CONTENT, LV_GRID_CONTENT, LV_GRID_CONTENT, LV_GRID_CONTENT, LV_GRID_TEMPLATE_LAST};

    lv_obj_set_grid_dsc_array(cont, grid_col_dsc, grid_row_dsc);
    lv_obj_set_grid_cell(title_label,   LV_GRID_ALIGN_START,    0, 2, LV_GRID_ALIGN_START, 0, 1);
    lv_obj_set_grid_cell(meter,         LV_GRID_ALIGN_START,    0, 2, LV_GRID_ALIGN_START, 1, 1);
    //lv_obj_set_grid_cell(bullet1,       LV_GRID_ALIGN_START,    0, 1, LV_GRID_ALIGN_START, 2, 1);
    //lv_obj_set_grid_cell(label1,        LV_GRID_ALIGN_STRETCH,  1, 1, LV_GRID_ALIGN_START, 2, 1);

    return meter;

}

 void  par_disp_create(lv_obj_t * parent)
 {
    uint8_t v;

    lv_obj_set_flex_flow(parent, LV_FLEX_FLOW_ROW_WRAP);

    static lv_coord_t grid_chart_row_dsc[] = {LV_GRID_CONTENT, LV_GRID_TEMPLATE_LAST};
    static lv_coord_t grid_chart_col_dsc[] = {LV_GRID_CONTENT, LV_GRID_TEMPLATE_LAST};

    static lv_coord_t grid_1_col_dsc[] = {LV_GRID_CONTENT, 5, LV_GRID_CONTENT, LV_GRID_FR(2), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
    static lv_coord_t grid_1_row_dsc[] = {LV_GRID_CONTENT, LV_GRID_CONTENT, 10, LV_GRID_CONTENT, LV_GRID_CONTENT, LV_GRID_TEMPLATE_LAST};

    lv_obj_t * motor_trl = lv_obj_create(parent);
    lv_obj_set_height(motor_trl, LV_SIZE_CONTENT);
    lv_obj_set_flex_grow(motor_trl, 1);
    lv_obj_set_grid_dsc_array(motor_trl, grid_chart_col_dsc, grid_chart_row_dsc);

    lv_obj_t * title = lv_label_create(motor_trl);
    lv_label_set_text(title, "Motor control");
    lv_obj_add_style(title, &style_title, 0);

    motor_status = lv_label_create(motor_trl);
    lv_label_set_recolor(motor_status, true);
    lv_label_set_text(motor_status, "#FF0000 Status:  device close!");
    lv_obj_add_style(motor_status, &style_title, 0);

    motor_pr_btn_open = lv_btn_create(motor_trl);
    lv_obj_set_height(motor_pr_btn_open, LV_SIZE_CONTENT);
    lv_obj_add_event_cb(motor_pr_btn_open, motor_pr_open_btn_event_handler, LV_EVENT_ALL, NULL);

    motor_label = lv_label_create(motor_pr_btn_open);
    lv_label_set_text(motor_label, "Open");
    lv_obj_center(motor_label);

    motor_pr_btn_close = lv_btn_create(motor_trl);
    lv_obj_set_height(motor_pr_btn_close, LV_SIZE_CONTENT);
    lv_obj_add_event_cb(motor_pr_btn_close, motor_pr_close_btn_event_handler, LV_EVENT_ALL, NULL);

    motor_label = lv_label_create(motor_pr_btn_close);
    lv_label_set_text(motor_label, "Close");
    lv_obj_center(motor_label);

    lv_obj_set_grid_cell(motor_trl,                 LV_GRID_ALIGN_START,    0, 3, LV_GRID_ALIGN_CENTER,  0, 1);
    lv_obj_set_grid_dsc_array(motor_trl, grid_1_col_dsc, grid_1_row_dsc);

    lv_obj_set_grid_cell(title,                 LV_GRID_ALIGN_START,        0, 1, LV_GRID_ALIGN_CENTER, 0, 1);
    lv_obj_set_grid_cell(motor_status,          LV_GRID_ALIGN_STRETCH,      0, 1, LV_GRID_ALIGN_START,  1, 1);

    lv_obj_set_grid_cell(motor_pr_btn_open,     LV_GRID_ALIGN_STRETCH,      4, 1, LV_GRID_ALIGN_CENTER, 0, 2);
    lv_obj_set_grid_cell(motor_pr_btn_close,    LV_GRID_ALIGN_STRETCH,      5, 1, LV_GRID_ALIGN_CENTER, 0, 2);

//-----------------------------------------------------------------------------------------------------------------------
    par1 = meter_box(parent, "Current", NULL);
    lv_obj_add_flag(lv_obj_get_parent(par1), LV_OBJ_FLAG_FLEX_IN_NEW_TRACK);

    lv_obj_set_style_pad_hor(par1, 10, 0);
    lv_obj_set_style_size(par1, 10, LV_PART_INDICATOR);
    lv_obj_set_style_radius(par1, LV_RADIUS_CIRCLE, LV_PART_INDICATOR);
    lv_obj_set_style_bg_opa(par1, LV_OPA_COVER, LV_PART_INDICATOR);
    lv_obj_set_style_bg_color(par1, lv_palette_darken(LV_PALETTE_GREY, 4), LV_PART_INDICATOR);
    lv_obj_set_style_outline_color(par1, lv_color_white(), LV_PART_INDICATOR);
    lv_obj_set_style_outline_width(par1, 3, LV_PART_INDICATOR);
    lv_obj_set_style_text_color(par1, lv_palette_darken(LV_PALETTE_GREY, 1), LV_PART_TICKS);

    scale = lv_meter_add_scale(par1);
    lv_meter_set_scale_range(par1, scale, 0, 30, 270, 360 - 225);
    lv_meter_set_scale_ticks(par1, scale, 21, 3, 17, lv_color_white());
    lv_meter_set_scale_major_ticks(par1, scale, 4, 4, 22, lv_color_white(), 15);

    cur_indic = lv_meter_add_arc(par1, scale, 10, lv_palette_main(LV_PALETTE_GREEN), 0);
    lv_meter_set_indicator_start_value(par1, cur_indic, 0);
    lv_meter_set_indicator_end_value(par1, cur_indic, 30);

    cur_indic = lv_meter_add_scale_lines(par1, scale, lv_palette_darken(LV_PALETTE_GREEN, 3), lv_palette_darken(LV_PALETTE_GREEN, 3), true, 0);
    lv_meter_set_indicator_start_value(par1, cur_indic, 0);
    lv_meter_set_indicator_end_value(par1, cur_indic, 30);

    cur_indic = lv_meter_add_needle_line(par1, scale, 4, lv_palette_darken(LV_PALETTE_GREY, 4), -25);

    cur_val_label = lv_label_create(par1);
    lv_label_set_text(cur_val_label , "0A");

   /* lv_obj_t * cur_unit_label = lv_label_create(par1);
    lv_label_set_text(cur_unit_label, "A");*/

    //-----------------------------------------------------------------------------------------------------------------------
    volt = meter_box(parent, "Voltage", NULL);

    lv_obj_set_style_pad_hor(volt, 10, 0);
    lv_obj_set_style_size(volt, 10, LV_PART_INDICATOR);
    lv_obj_set_style_radius(volt, LV_RADIUS_CIRCLE, LV_PART_INDICATOR);
    lv_obj_set_style_bg_opa(volt, LV_OPA_COVER, LV_PART_INDICATOR);
    lv_obj_set_style_bg_color(volt, lv_palette_darken(LV_PALETTE_GREY, 4), LV_PART_INDICATOR);
    lv_obj_set_style_outline_color(volt, lv_color_white(), LV_PART_INDICATOR);
    lv_obj_set_style_outline_width(volt, 3, LV_PART_INDICATOR);
    lv_obj_set_style_text_color(volt, lv_palette_darken(LV_PALETTE_GREY, 1), LV_PART_TICKS);

    scale = lv_meter_add_scale(volt);
    lv_meter_set_scale_range(volt, scale, 0, 240, 270, 360 - 225);
    lv_meter_set_scale_ticks(volt, scale, 21, 3, 17, lv_color_white());
    lv_meter_set_scale_major_ticks(volt, scale, 4, 4, 22, lv_color_white(), 15);

    volt_indic = lv_meter_add_arc(volt, scale, 10, lv_palette_main(LV_PALETTE_BLUE), 0);
    lv_meter_set_indicator_start_value(volt, volt_indic, 0);
    lv_meter_set_indicator_end_value(volt, volt_indic, 240);

    volt_indic = lv_meter_add_scale_lines(volt, scale, lv_palette_darken(LV_PALETTE_BLUE, 3), lv_palette_darken(LV_PALETTE_BLUE, 3), true, 0);
    lv_meter_set_indicator_start_value(volt, volt_indic, 0);
    lv_meter_set_indicator_end_value(volt, volt_indic, 240);

    volt_indic = lv_meter_add_needle_line(volt, scale, 4, lv_palette_darken(LV_PALETTE_GREY, 4), -25);

    volt_val_label = lv_label_create(volt);
    lv_label_set_text(volt_val_label, "0V");
    lv_obj_add_style(volt_val_label, &style_title, 0);

    /*lv_obj_t * volt_unit_label = lv_label_create(volt);
    lv_label_set_text(volt_unit_label, "V");*/

//-----------------------------------------------------------------------------------------------------------------------

    spd = meter_box(parent, "Speed", NULL);
    lv_obj_set_style_pad_hor(spd, 10, 0);
    lv_obj_set_style_size(spd, 10, LV_PART_INDICATOR);
    lv_obj_set_style_radius(spd, LV_RADIUS_CIRCLE, LV_PART_INDICATOR);
    lv_obj_set_style_bg_opa(spd, LV_OPA_COVER, LV_PART_INDICATOR);
    lv_obj_set_style_bg_color(spd, lv_palette_darken(LV_PALETTE_GREY, 4), LV_PART_INDICATOR);
    lv_obj_set_style_outline_color(spd, lv_color_white(), LV_PART_INDICATOR);
    lv_obj_set_style_outline_width(spd, 3, LV_PART_INDICATOR);
    lv_obj_set_style_text_color(spd, lv_palette_darken(LV_PALETTE_GREY, 1), LV_PART_TICKS);

    scale = lv_meter_add_scale(spd);
    lv_meter_set_scale_range(spd, scale, 0, 120, 270, 360 - 225);
    lv_meter_set_scale_ticks(spd, scale, 21, 3, 17, lv_color_white());
    lv_meter_set_scale_major_ticks(spd, scale, 4, 4, 22, lv_color_white(), 15);

    spd_indic = lv_meter_add_arc(spd, scale, 10, lv_palette_main(LV_PALETTE_BROWN), 0);
    lv_meter_set_indicator_start_value(spd, spd_indic, 0);
    lv_meter_set_indicator_end_value(spd, spd_indic, 120);

    spd_indic = lv_meter_add_scale_lines(spd, scale, lv_palette_darken(LV_PALETTE_BROWN, 3), lv_palette_darken(LV_PALETTE_BROWN, 3), true, 0);
    lv_meter_set_indicator_start_value(spd, spd_indic, 0);
    lv_meter_set_indicator_end_value(spd, spd_indic, 120);

    spd_indic = lv_meter_add_needle_line(spd, scale, 4, lv_palette_darken(LV_PALETTE_GREY, 4), -25);

    spd_val_label = lv_label_create(spd);
    lv_label_set_text(spd_val_label, "0km/h");

    lv_obj_add_style(spd_val_label, &style_title, 0);
    /*lv_obj_t * spd_unit_label = lv_label_create(spd);
    lv_label_set_text(spd_unit_label, "km/h");*/

    lv_obj_update_layout(parent);
    lv_coord_t meter_w = lv_obj_get_width(par1);
    lv_obj_set_height(par1, meter_w);
    lv_obj_set_height(volt, meter_w);
    lv_obj_set_height(spd, meter_w);

    //cur
    lv_obj_align(cur_val_label, LV_ALIGN_TOP_LEFT, 65, lv_pct(80));
    //lv_obj_align_to(cur_unit_label, cur_val_label, LV_ALIGN_OUT_RIGHT_BOTTOM, 10, 0);

    //volt
    lv_obj_align(volt_val_label, LV_ALIGN_TOP_LEFT, 65, lv_pct(80));
    //lv_obj_align_to(volt_unit_label, volt_val_label, LV_ALIGN_OUT_RIGHT_BOTTOM, 15, 0);
    //spd
    lv_obj_align(spd_val_label, LV_ALIGN_TOP_LEFT, 60, lv_pct(80));
    //lv_obj_align_to(spd_unit_label, spd_val_label, LV_ALIGN_OUT_RIGHT_BOTTOM, 15, 0);
 }


 void motor_setvalue(uint8_t cr, uint8_t vt, uint8_t sp)
 {
    lv_meter_set_indicator_value(par1, cur_indic, cr);
    lv_meter_set_indicator_value(volt, volt_indic, vt);
    lv_meter_set_indicator_value(spd, spd_indic, sp);

    lv_label_set_text_fmt(cur_val_label,    "%dA",cr);
    lv_label_set_text_fmt(volt_val_label,   "%dV",vt);
    lv_label_set_text_fmt(spd_val_label,    "%dkm/h",sp);

 }


