/* Page Startup */
#include "Page.h"

static lv_timer_t* task1 = NULL;

void Startup_cb(lv_timer_t* tmr)
{
    lv_timer_del(task1);
    lv_pm_open_page(1, NULL);
}

static void obj_anim_startup(lv_anim_t* a)
{
    lv_obj_t* obj = (lv_obj_t*)a->user_data;
    _ui_flag_modify(obj, LV_OBJ_FLAG_HIDDEN, 1);
}

static void startup_anim_step1(lv_obj_t* TargetObject, int delay)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 600);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_width);
    lv_anim_set_values(&PropertyAnimation_0, 0, 80);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_in_out);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_width);
    lv_anim_start(&PropertyAnimation_0);
}

static void startup_anim_step2(lv_obj_t* TargetObject, int delay)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 600);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_y);
    lv_anim_set_values(&PropertyAnimation_0, 0, -15);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_in_out);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_y);
    lv_anim_set_start_cb(&PropertyAnimation_0, obj_anim_startup);
    lv_anim_start(&PropertyAnimation_0);
}

void InitPageStartup(lv_obj_t* page)
{
    lv_obj_t* pagestartup = lv_obj_create(page);
    lv_obj_align(pagestartup, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_size(pagestartup, lv_disp_get_hor_res(NULL), lv_disp_get_ver_res(NULL));
    lv_obj_set_style_radius(pagestartup, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(pagestartup, 0, LV_PART_MAIN | LV_STATE_DEFAULT); //邊框
    /* 禁止滾動 */
    lv_obj_clear_flag(pagestartup, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

    static lv_style_t style_page;
    if (style_page.prop_cnt > 1)
        lv_style_reset(&style_page);
    else
        lv_style_init(&style_page);
    lv_style_set_bg_color(&style_page, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_bg_opa(&style_page, 255);
    lv_obj_add_style(pagestartup, &style_page, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes label_1
    lv_obj_t* startup_label_1;
    startup_label_1 = lv_label_create(pagestartup);
    lv_obj_align(startup_label_1, LV_ALIGN_CENTER, 0, 10);
    // lv_obj_set_pos(label_1, 340, 224);
    lv_obj_set_size(startup_label_1, 120, 32);
    lv_obj_set_scrollbar_mode(startup_label_1, LV_SCROLLBAR_MODE_OFF);
    lv_label_set_text(startup_label_1, "LVGL");
    lv_label_set_long_mode(startup_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_add_flag(startup_label_1, LV_OBJ_FLAG_HIDDEN);
    // Write style state: LV_STATE_DEFAULT for  label_1_style
    static lv_style_t  label_1_style;
    if ( label_1_style.prop_cnt > 1)
        lv_style_reset(& label_1_style);
    else
        lv_style_init(& label_1_style);
    lv_style_set_radius(& label_1_style, 0);
    lv_style_set_bg_color(& label_1_style, lv_color_make(0x21, 0x95, 0xf6));
    lv_style_set_bg_grad_color(& label_1_style, lv_color_make(0x21, 0x95, 0xf6));
    lv_style_set_bg_grad_dir(& label_1_style, LV_GRAD_DIR_NONE);
    lv_style_set_bg_opa(& label_1_style, 0);
    lv_style_set_shadow_width(& label_1_style, 1);
    lv_style_set_shadow_color(& label_1_style, lv_color_make(0xcb, 0x8a, 0x1a));
    lv_style_set_shadow_opa(& label_1_style, 0);
    lv_style_set_shadow_spread(& label_1_style, 0);
    lv_style_set_shadow_ofs_x(& label_1_style, 0);
    lv_style_set_shadow_ofs_y(& label_1_style, 0);
    lv_style_set_text_color(& label_1_style, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_text_font(& label_1_style, &lv_font_montserratMedium_24);
    lv_style_set_text_letter_space(& label_1_style, 2);
    lv_style_set_text_line_space(& label_1_style, 0);
    lv_style_set_text_align(& label_1_style, LV_TEXT_ALIGN_CENTER);
    lv_style_set_pad_left(& label_1_style, 0);
    lv_style_set_pad_right(& label_1_style, 0);
    lv_style_set_pad_top(& label_1_style, 5);
    lv_style_set_pad_bottom(& label_1_style, 0);
    lv_obj_add_style(startup_label_1, & label_1_style, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write codes startup_cont_1
    lv_obj_t* startup_cont_1;
    startup_cont_1 = lv_obj_create(pagestartup);
    lv_obj_align(startup_cont_1, LV_ALIGN_CENTER, 0, 20);
    // lv_obj_set_pos(startup_cont_1, 395, 235);
    lv_obj_set_size(startup_cont_1, 8, 8);
    lv_obj_set_scrollbar_mode(startup_cont_1, LV_SCROLLBAR_MODE_OFF);

    // Write style state: LV_STATE_DEFAULT for cont_1_style
    static lv_style_t cont_1_style;
    if (cont_1_style.prop_cnt > 1)
        lv_style_reset(&cont_1_style);
    else
        lv_style_init(&cont_1_style);
    lv_style_set_radius(&cont_1_style, 15);
    lv_style_set_bg_color(&cont_1_style, lv_color_make(0xf3, 0x9c, 0x12));
    lv_style_set_bg_grad_color(&cont_1_style, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_bg_grad_dir(&cont_1_style, LV_GRAD_DIR_NONE);
    lv_style_set_bg_opa(&cont_1_style, 255);
    lv_style_set_border_color(&cont_1_style, lv_color_make(0x21, 0x95, 0xf6));
    lv_style_set_border_width(&cont_1_style, 2);
    lv_style_set_border_opa(&cont_1_style, 0);
    lv_style_set_pad_left(&cont_1_style, 0);
    lv_style_set_pad_right(&cont_1_style, 0);
    lv_style_set_pad_top(&cont_1_style, 0);
    lv_style_set_pad_bottom(&cont_1_style, 0);
    lv_obj_add_style(startup_cont_1, &cont_1_style, LV_PART_MAIN | LV_STATE_DEFAULT);
    task1 = lv_timer_create(Startup_cb, 1500, NULL);

    startup_anim_step1(startup_cont_1, 0);
    startup_anim_step2(startup_label_1, 400);

}

void DeInitPageStartup(lv_obj_t* page)
{
    // 釋放自己申請的內存
}
