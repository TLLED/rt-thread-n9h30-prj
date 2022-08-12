//#include "../../lv_demo.h"
//#include "lv_examples/src/lv_demo.h"
#include "lv_demo_widgets.h"

static lv_style_t style_title;
static lv_style_t style_bullet;

static lv_obj_t * meter1;
static lv_obj_t * meter2;
static lv_obj_t * meter3;

static lv_obj_t * par1;
static lv_obj_t * volt;
static lv_obj_t * spd;


static lv_obj_t * meter_box(lv_obj_t * parent, const char * title, const char * text1, const char * text2, const char * text3)
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

    lv_obj_t * bullet1 = lv_obj_create(cont);
    lv_obj_set_size(bullet1, 13, 13);
    lv_obj_remove_style(bullet1, NULL, LV_PART_SCROLLBAR);
    lv_obj_add_style(bullet1, &style_bullet, 0);
    lv_obj_set_style_bg_color(bullet1, lv_palette_main(LV_PALETTE_RED), 0);
    lv_obj_t * label1 = lv_label_create(cont);
    lv_label_set_text(label1, text1);

    lv_obj_t * bullet2 = lv_obj_create(cont);
    lv_obj_set_size(bullet2, 13, 13);
    lv_obj_remove_style(bullet2, NULL, LV_PART_SCROLLBAR);
    lv_obj_add_style(bullet2, &style_bullet, 0);
    lv_obj_set_style_bg_color(bullet2, lv_palette_main(LV_PALETTE_BLUE), 0);
    lv_obj_t * label2 = lv_label_create(cont);
    lv_label_set_text(label2, text2);

    /*lv_obj_t * bullet3 = lv_obj_create(cont);
    lv_obj_set_size(bullet3, 13, 13);
    lv_obj_remove_style(bullet3,  NULL, LV_PART_SCROLLBAR);
    lv_obj_add_style(bullet3, &style_bullet, 0);
    lv_obj_set_style_bg_color(bullet3, lv_palette_main(LV_PALETTE_GREEN), 0);
    lv_obj_t * label3 = lv_label_create(cont);
    lv_label_set_text(label3, text3);*/

    /*if(disp_size == DISP_MEDIUM) {
        static lv_coord_t grid_col_dsc[] = {LV_GRID_CONTENT, LV_GRID_FR(1), LV_GRID_CONTENT,LV_GRID_FR(8), LV_GRID_TEMPLATE_LAST};
        static lv_coord_t grid_row_dsc[] = {LV_GRID_CONTENT, LV_GRID_FR(1), LV_GRID_CONTENT, LV_GRID_CONTENT, LV_GRID_CONTENT, LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};

        lv_obj_set_grid_dsc_array(cont, grid_col_dsc, grid_row_dsc);
        lv_obj_set_grid_cell(title_label, LV_GRID_ALIGN_START, 0, 4, LV_GRID_ALIGN_START, 0, 1);
        lv_obj_set_grid_cell(meter, LV_GRID_ALIGN_START, 0, 1, LV_GRID_ALIGN_START, 1, 3);
        lv_obj_set_grid_cell(bullet1, LV_GRID_ALIGN_START, 2, 1, LV_GRID_ALIGN_CENTER, 2, 1);
        lv_obj_set_grid_cell(bullet2, LV_GRID_ALIGN_START, 2, 1, LV_GRID_ALIGN_CENTER, 3, 1);
        lv_obj_set_grid_cell(bullet3, LV_GRID_ALIGN_START, 2, 1, LV_GRID_ALIGN_CENTER, 4, 1);
        lv_obj_set_grid_cell(label1, LV_GRID_ALIGN_STRETCH, 3, 1, LV_GRID_ALIGN_CENTER, 2, 1);
        lv_obj_set_grid_cell(label2, LV_GRID_ALIGN_STRETCH, 3, 1, LV_GRID_ALIGN_CENTER, 3, 1);
        lv_obj_set_grid_cell(label3, LV_GRID_ALIGN_STRETCH, 3, 1, LV_GRID_ALIGN_CENTER, 4, 1);
    }
    else {*/
        static lv_coord_t grid_col_dsc[] = {LV_GRID_CONTENT, LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
        static lv_coord_t grid_row_dsc[] = {LV_GRID_CONTENT, LV_GRID_CONTENT, LV_GRID_CONTENT, LV_GRID_CONTENT, LV_GRID_TEMPLATE_LAST};
        lv_obj_set_grid_dsc_array(cont, grid_col_dsc, grid_row_dsc);
        lv_obj_set_grid_cell(title_label, LV_GRID_ALIGN_START, 0, 2, LV_GRID_ALIGN_START, 0, 1);
        lv_obj_set_grid_cell(meter, LV_GRID_ALIGN_START, 0, 2, LV_GRID_ALIGN_START, 1, 1);
        lv_obj_set_grid_cell(bullet1, LV_GRID_ALIGN_START, 0, 1, LV_GRID_ALIGN_START, 2, 1);
        lv_obj_set_grid_cell(bullet2, LV_GRID_ALIGN_START, 0, 1, LV_GRID_ALIGN_START, 3, 1);
        //lv_obj_set_grid_cell(bullet3, LV_GRID_ALIGN_START, 0, 1, LV_GRID_ALIGN_START, 4, 1);
        lv_obj_set_grid_cell(label1, LV_GRID_ALIGN_STRETCH, 1, 1, LV_GRID_ALIGN_START, 2, 1);
        lv_obj_set_grid_cell(label2, LV_GRID_ALIGN_STRETCH, 1, 1, LV_GRID_ALIGN_START, 3, 1);
        //lv_obj_set_grid_cell(label3, LV_GRID_ALIGN_STRETCH, 1, 1, LV_GRID_ALIGN_START, 4, 1);
    //}


    return meter;

}

 void  par_disp_create(lv_obj_t * parent)
 {
    uint8_t v;
    lv_obj_set_flex_flow(parent, LV_FLEX_FLOW_ROW_WRAP);

    static lv_coord_t grid_chart_row_dsc[] = {LV_GRID_CONTENT, LV_GRID_FR(1), 10, LV_GRID_TEMPLATE_LAST};
    static lv_coord_t grid_chart_col_dsc[] = {20, LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};

    lv_meter_scale_t * scale;
    lv_meter_indicator_t *indic;

//-----------------------------------------------------------------------------------------------------------------------
    par1 = meter_box(parent, "Current", "Revenue: 63%", "Sales: 44%", "Costs: 58%");

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

    indic = lv_meter_add_arc(par1, scale, 10, lv_palette_main(LV_PALETTE_GREEN), 0);
    lv_meter_set_indicator_start_value(par1, indic, 0);
    lv_meter_set_indicator_end_value(par1, indic, 30);

    indic = lv_meter_add_scale_lines(par1, scale, lv_palette_darken(LV_PALETTE_GREEN, 3), lv_palette_darken(LV_PALETTE_GREEN, 3), true, 0);
    lv_meter_set_indicator_start_value(par1, indic, 0);
    lv_meter_set_indicator_end_value(par1, indic, 30);
/*
    indic = lv_meter_add_arc(par1, scale, 10, lv_palette_main(LV_PALETTE_GREEN), 0);
    lv_meter_set_indicator_start_value(par1, indic, 10);
    lv_meter_set_indicator_end_value(par1, indic, 20);

    indic = lv_meter_add_scale_lines(par1, scale, lv_palette_darken(LV_PALETTE_GREEN, 3), lv_palette_darken(LV_PALETTE_GREEN, 3), true, 0);
    lv_meter_set_indicator_start_value(par1, indic, 10);
    lv_meter_set_indicator_end_value(par1, indic, 20);

    indic = lv_meter_add_arc(par1, scale, 10, lv_palette_main(LV_PALETTE_GREEN), 0);
    lv_meter_set_indicator_start_value(par1, indic, 20);
    lv_meter_set_indicator_end_value(par1, indic, 30);

    indic = lv_meter_add_scale_lines(par1, scale, lv_palette_darken(LV_PALETTE_GREEN, 3), lv_palette_darken(LV_PALETTE_GREEN, 3), true, 0);
    lv_meter_set_indicator_start_value(par1, indic, 20);
    lv_meter_set_indicator_end_value(par1, indic, 30);
*/
    indic = lv_meter_add_needle_line(par1, scale, 4, lv_palette_darken(LV_PALETTE_GREY, 4), -25);

    lv_obj_t * cur_unit_label = lv_label_create(par1);
    lv_label_set_text(cur_unit_label, "A");

    v=25;
    lv_meter_set_indicator_value(par1, indic, v);

    //-----------------------------------------------------------------------------------------------------------------------
    volt = meter_box(parent, "Voltage", "Revenue: 63%", "Sales: 44%", "Costs: 58%");

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

    indic = lv_meter_add_arc(volt, scale, 10, lv_palette_main(LV_PALETTE_BLUE), 0);
    lv_meter_set_indicator_start_value(volt, indic, 0);
    lv_meter_set_indicator_end_value(volt, indic, 240);

    indic = lv_meter_add_scale_lines(volt, scale, lv_palette_darken(LV_PALETTE_BLUE, 3), lv_palette_darken(LV_PALETTE_BLUE, 3), true, 0);
    lv_meter_set_indicator_start_value(volt, indic, 0);
    lv_meter_set_indicator_end_value(volt, indic, 240);
/*
    indic = lv_meter_add_arc(volt, scale, 10, lv_palette_main(LV_PALETTE_BLUE), 0);
    lv_meter_set_indicator_start_value(volt, indic, 80);
    lv_meter_set_indicator_end_value(volt, indic, 160);

    indic = lv_meter_add_scale_lines(volt, scale, lv_palette_darken(LV_PALETTE_BLUE, 3), lv_palette_darken(LV_PALETTE_BLUE, 3), true, 0);
    lv_meter_set_indicator_start_value(volt, indic, 80);
    lv_meter_set_indicator_end_value(volt, indic, 160);

    indic = lv_meter_add_arc(volt, scale, 10, lv_palette_main(LV_PALETTE_BLUE), 0);
    lv_meter_set_indicator_start_value(volt, indic, 160);
    lv_meter_set_indicator_end_value(volt, indic, 240);

    indic = lv_meter_add_scale_lines(volt, scale, lv_palette_darken(LV_PALETTE_BLUE, 3), lv_palette_darken(LV_PALETTE_BLUE, 3), true, 0);
    lv_meter_set_indicator_start_value(volt, indic, 160);
    lv_meter_set_indicator_end_value(volt, indic, 240);
*/
    indic = lv_meter_add_needle_line(volt, scale, 4, lv_palette_darken(LV_PALETTE_GREY, 4), -25);

    lv_obj_t * volt_unit_label = lv_label_create(volt);
    lv_label_set_text(volt_unit_label, "V");

    v=100;
    lv_meter_set_indicator_value(volt, indic, v);
//-----------------------------------------------------------------------------------------------------------------------

    spd = meter_box(parent, "Speed", "Low speed", " ", "High Speed");
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

    indic = lv_meter_add_arc(spd, scale, 10, lv_palette_main(LV_PALETTE_BROWN), 0);
    lv_meter_set_indicator_start_value(spd, indic, 0);
    lv_meter_set_indicator_end_value(spd, indic, 120);

    indic = lv_meter_add_scale_lines(spd, scale, lv_palette_darken(LV_PALETTE_BROWN, 3), lv_palette_darken(LV_PALETTE_BROWN, 3), true, 0);
    lv_meter_set_indicator_start_value(spd, indic, 0);
    lv_meter_set_indicator_end_value(spd, indic, 120);

    indic = lv_meter_add_needle_line(spd, scale, 4, lv_palette_darken(LV_PALETTE_GREY, 4), -25);

    lv_obj_t * mbps_label = lv_label_create(spd);
    lv_label_set_text(mbps_label, "-");
    lv_obj_add_style(mbps_label, &style_title, 0);

    lv_obj_t * mbps_unit_label = lv_label_create(spd);
    lv_label_set_text(mbps_unit_label, "Mbps");

    v=25;
    lv_meter_set_indicator_value(spd, indic, v);
    //lv_label_set_text_fmt(mbps_label, "%d", v);
    /*
    lv_meter_set_indicator_value(meter3, var, v);

    lv_obj_t * label = lv_obj_get_child(meter3, 0);
    lv_label_set_text_fmt(label, "%d", v);
    */


/*
    lv_anim_init(&a);
    lv_anim_set_values(&a, 10, 60);
    lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);
    lv_anim_set_exec_cb(&a, meter3_anim_cb);
    lv_anim_set_var(&a, indic);
    lv_anim_set_time(&a, 4100);
    lv_anim_set_playback_time(&a, 800);
    lv_anim_start(&a);
*/
    lv_obj_update_layout(parent);
    lv_coord_t meter_w = lv_obj_get_width(par1);
    lv_obj_set_height(par1, meter_w);
    lv_obj_set_height(volt, meter_w);
    lv_obj_set_height(spd, meter_w);

    lv_obj_align(cur_unit_label, LV_ALIGN_TOP_MID, 2, lv_pct(72));
    lv_obj_align(mbps_label, LV_ALIGN_TOP_MID, 10, lv_pct(55));
    lv_obj_align_to(mbps_unit_label, mbps_label, LV_ALIGN_OUT_RIGHT_BOTTOM, 10, 0);
 }



