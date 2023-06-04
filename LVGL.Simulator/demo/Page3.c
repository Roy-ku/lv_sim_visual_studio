/* Page 3 */
#include "Page.h"
//#include "./SLgenerated.c"
static void page3_btn_1_event_handler(lv_event_t* e);
static void Style_Set_label_1(lv_obj_t* obj);

static void Style_Set_label_1(lv_obj_t* obj)
{
    // Write style state: LV_STATE_DEFAULT for style_page_home_label_1_main_main_default
    static lv_style_t style_page_home_label_1_main_main_default = { 0 };
    if (style_page_home_label_1_main_main_default.prop_cnt > 1)
        lv_style_reset(&style_page_home_label_1_main_main_default);
    else
        lv_style_init(&style_page_home_label_1_main_main_default);
    lv_style_set_radius(&style_page_home_label_1_main_main_default, 0);
    lv_style_set_bg_color(&style_page_home_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
    lv_style_set_bg_grad_color(&style_page_home_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
    lv_style_set_bg_grad_dir(&style_page_home_label_1_main_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_bg_opa(&style_page_home_label_1_main_main_default, 0);
    lv_style_set_text_color(&style_page_home_label_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
    lv_style_set_text_font(&style_page_home_label_1_main_main_default, &lv_font_montserrat_24);
    lv_style_set_text_letter_space(&style_page_home_label_1_main_main_default, 4);
    lv_style_set_text_line_space(&style_page_home_label_1_main_main_default, 0);
    lv_style_set_text_align(&style_page_home_label_1_main_main_default, LV_TEXT_ALIGN_CENTER);
    lv_style_set_pad_left(&style_page_home_label_1_main_main_default, 0);
    lv_style_set_pad_right(&style_page_home_label_1_main_main_default, 0);
    lv_style_set_pad_top(&style_page_home_label_1_main_main_default, 8);
    lv_style_set_pad_bottom(&style_page_home_label_1_main_main_default, 0);
    lv_obj_add_style(obj, &style_page_home_label_1_main_main_default, LV_PART_MAIN | LV_STATE_DEFAULT);
}

void img_zoom_Animation(lv_obj_t* TargetObject, int delay)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 1000);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_image_zoom);
    lv_anim_set_values(&PropertyAnimation_0, 0, -24);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_out);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_image_zoom);
    lv_anim_start(&PropertyAnimation_0);

}

void panel_xmove_Animation(lv_obj_t* TargetObject, int delay)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 1000);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_x);
    lv_anim_set_values(&PropertyAnimation_0, 0, 600);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_out);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_x);
    lv_anim_start(&PropertyAnimation_0);

}

static void page3_btn_1_event_handler(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);
    
    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        lv_pm_open_page(1, &options);
    }
    break;
    default:
        break;
    }
}

static void page3_btn_2_event_handler(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);

    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        lv_pm_enter_sleepmode();
    }
    break;
    default:
        break;
    }
}

void InitPages3(lv_obj_t* page)
{
    lv_obj_t* ui_Image2;
    ui_Image2 = lv_img_create(page);
    lv_img_set_src(ui_Image2, &ui_img_powertip001_png);
    lv_obj_set_width(ui_Image2, 800);
    lv_obj_set_height(ui_Image2, 480);
    lv_obj_set_align(ui_Image2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_pivot(ui_Image2, 400, 240);
    lv_img_set_zoom(ui_Image2, 280);
    /* 禁止滾動 */
    lv_obj_clear_flag(ui_Image2, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

    /* 建立label_1 */
    lv_obj_t* Pages3_label_1 = lv_label_create(page);
    // lv_obj_set_pos(Pages3_label_1, 400, 80);

    Style_Set_label_1(Pages3_label_1);
    lv_obj_align(Pages3_label_1, LV_ALIGN_CENTER, 0, 100);
    lv_obj_set_size(Pages3_label_1, 102, 37);
    lv_obj_set_scrollbar_mode(Pages3_label_1, LV_SCROLLBAR_MODE_OFF);
    lv_label_set_text(Pages3_label_1, "Page3");
    lv_label_set_long_mode(Pages3_label_1, LV_LABEL_LONG_WRAP);


    /* 建立btn_1 */
    lv_obj_t* btn_1 = lv_btn_create(page);
    lv_obj_t* btn_1_label;

    btn_1_label = lv_label_create(btn_1);
    lv_label_set_text(btn_1_label, "page1");
    lv_obj_align(btn_1, LV_ALIGN_CENTER, 200, 200);
    //lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);

    lv_obj_add_event_cb(btn_1, page3_btn_1_event_handler, LV_EVENT_CLICKED, NULL);

    /* 建立btn_2 */
    lv_obj_t* btn_2 = lv_btn_create(page);
    lv_obj_t* btn_2_label;

    btn_2_label = lv_label_create(btn_2);
    lv_label_set_text(btn_2_label, "ZZ");
    lv_obj_align(btn_2, LV_ALIGN_CENTER, 300, 200);
    //lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);

    lv_obj_t* ui_Panel1;
    ui_Panel1 = lv_obj_create(page);
    lv_obj_set_width(ui_Panel1, 600);
    lv_obj_set_height(ui_Panel1, 480);
    lv_obj_set_x(ui_Panel1, -600);
    lv_obj_set_y(ui_Panel1, 0);
    lv_obj_set_align(ui_Panel1, LV_ALIGN_LEFT_MID);
    lv_obj_clear_flag(ui_Panel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Panel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel1, 150, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Panel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t* ui_Panel1_label;
    ui_Panel1_label = lv_label_create(ui_Panel1);
    lv_label_set_text(ui_Panel1_label, "P05D00071");
    lv_obj_set_style_text_font(ui_Panel1_label, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align(ui_Panel1_label, LV_ALIGN_CENTER, 0, -200);

    lv_obj_t* ui_Panel1_label2;
    ui_Panel1_label2 = lv_label_create(ui_Panel1);
    lv_label_set_text(ui_Panel1_label2, "CPU:STM32H750@480MHz");
    //lv_obj_set_style_text_font(ui_Panel1_label2, &lv_font_montserratMedium_24, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align(ui_Panel1_label2, LV_ALIGN_CENTER, 0, -150);

    lv_obj_t* ui_Panel1_label3;
    ui_Panel1_label3 = lv_label_create(ui_Panel1);
    lv_label_set_text(ui_Panel1_label3, "External Flash:32MB");
    //lv_obj_set_style_text_font(ui_Panel1_label2, &lv_font_montserratMedium_24, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align(ui_Panel1_label3, LV_ALIGN_CENTER, 0, -130);

    lv_obj_t* ui_Panel1_label4;
    ui_Panel1_label4 = lv_label_create(ui_Panel1);
    lv_label_set_text(ui_Panel1_label4, "SDRAM:16MB");
    //lv_obj_set_style_text_font(ui_Panel1_label2, &lv_font_montserratMedium_24, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align(ui_Panel1_label4, LV_ALIGN_CENTER, 0, -110);

    lv_obj_add_event_cb(btn_2, page3_btn_2_event_handler, LV_EVENT_CLICKED, NULL);
    panel_xmove_Animation(ui_Panel1, 0);
    img_zoom_Animation(ui_Image2, 0);
    lv_pm_obj_anima_smooth_in(ui_Panel1_label, ANIM_DIR_TOP,1000);
    lv_pm_obj_anima_smooth_in(ui_Panel1_label2, ANIM_DIR_LEFT, 1500);
    lv_pm_obj_anima_smooth_in(ui_Panel1_label3, ANIM_DIR_LEFT, 1700);
    lv_pm_obj_anima_smooth_in(ui_Panel1_label4, ANIM_DIR_LEFT, 1900);
}

void DeInitPages3(lv_obj_t* page)
{
    // 釋放自己申請的內存
}
