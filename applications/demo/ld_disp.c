//#include "../../lv_demo.h"
//#include "lv_examples/src/lv_demo.h"
#include "lv_demo_widgets.h"

static lv_style_t style_title;
static lv_style_t style_bullet;

static lv_obj_t * chart1;
static lv_obj_t * chart2;
static lv_obj_t * chart3;

static lv_chart_series_t * ser1;
static lv_chart_series_t * ser2;
static lv_chart_series_t * ser3;
static lv_chart_series_t * ser4;



 void  ld_disp_create(lv_obj_t * parent)
 {
    uint16_t i;
    uint8_t v;
    lv_obj_set_flex_flow(parent, LV_FLEX_FLOW_ROW_WRAP);

    static lv_coord_t grid_chart_row_dsc[] = {LV_GRID_CONTENT, LV_GRID_FR(1), 10, LV_GRID_TEMPLATE_LAST};
    static lv_coord_t grid_chart_col_dsc[] = {20, LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};

    lv_obj_t * chart1_cont = lv_obj_create(parent);
    lv_obj_set_flex_grow(chart1_cont, 1);
    lv_obj_set_grid_dsc_array(chart1_cont, grid_chart_col_dsc, grid_chart_row_dsc);

    lv_obj_set_height(chart1_cont, LV_PCT(300));
    lv_obj_set_style_max_height(chart1_cont, 350, 0);

    lv_obj_t * title = lv_label_create(chart1_cont);
    lv_label_set_text(title, "can rx line graph:");
    lv_obj_add_style(title, &style_title, 0);
    lv_obj_set_grid_cell(title, LV_GRID_ALIGN_START, 0, 2, LV_GRID_ALIGN_START, 0, 1);

    //chart1--------------------------------------------------------------------------------
    chart1 = lv_chart_create(chart1_cont);
    lv_group_add_obj(lv_group_get_default(), chart1);
    lv_obj_add_flag(chart1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_set_grid_cell(chart1, LV_GRID_ALIGN_STRETCH, 1, 1, LV_GRID_ALIGN_STRETCH, 1, 1);
    lv_chart_set_type(chart1, LV_CHART_TYPE_LINE);
    lv_chart_set_range(chart1, LV_CHART_AXIS_PRIMARY_Y, 0, 250);

    lv_chart_set_axis_tick(chart1, LV_CHART_AXIS_PRIMARY_Y, 0, 0, 6, 1, true, 100);
    lv_chart_set_axis_tick(chart1, LV_CHART_AXIS_PRIMARY_X, 0, 0, 20, 1, true, 100);

    lv_chart_set_div_line_count(chart1, 0, 20);
    lv_chart_set_point_count(chart1, 20);
  //  lv_obj_add_event_cb(chart1, chart_event_cb, LV_EVENT_ALL, NULL);
    //if(disp_size == DISP_SMALL) lv_chart_set_zoom_x(chart1, 256 * 3);
    //else if(disp_size == DISP_MEDIUM) lv_chart_set_zoom_x(chart1, 256 * 2);

    lv_obj_set_style_border_side(chart1, LV_BORDER_SIDE_LEFT | LV_BORDER_SIDE_BOTTOM, 0);
    lv_obj_set_style_radius(chart1, 0, 0);

    ser1 = lv_chart_add_series(chart1, lv_palette_main(LV_PALETTE_BLUE),    LV_CHART_AXIS_PRIMARY_Y);
    ser2 = lv_chart_add_series(chart1, lv_palette_main(LV_PALETTE_GREEN),   LV_CHART_AXIS_PRIMARY_Y);
    ser3 = lv_chart_add_series(chart1, lv_palette_main(LV_PALETTE_RED),     LV_CHART_AXIS_PRIMARY_Y);
    ser4 = lv_chart_add_series(chart1, lv_palette_main(LV_PALETTE_YELLOW),  LV_CHART_AXIS_PRIMARY_Y);


    for(i=0;i<60;i++)
    {
        lv_chart_set_next_value(chart1, ser1, lv_rand(0, 100));
        lv_chart_set_next_value(chart1, ser2, lv_rand(0, 100));
        lv_chart_set_next_value(chart1, ser3, lv_rand(0, 100));
        lv_chart_set_next_value(chart1, ser4, lv_rand(0, 100));

    }
 }


 void chart_set_value( uint8_t se1, uint8_t se2, uint8_t se3, uint8_t se4)
 {
     lv_chart_set_next_value(chart1, ser1, se1);
     lv_chart_set_next_value(chart1, ser2, se2);
     lv_chart_set_next_value(chart1, ser3, se3);
     lv_chart_set_next_value(chart1, ser4, se4);

 }



