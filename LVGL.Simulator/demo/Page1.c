/* Page 1 */
#include "Page.h"
lv_anim_t PropertyAnimation_0;

static void page1_btn_1_event_handler(lv_event_t* e);
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

static void page1_btn_1_event_handler(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        lv_pm_open_page(2, &options);
    }
    break;
    default:
        break;
    }
}

static void page1_btn_2_event_handler(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        lv_pm_open_page(3, &options);
    }
    break;
    default:
        break;
    }
}

void InitPages1(lv_obj_t* page)
{
    lv_obj_t* ui_Panel2;
    lv_obj_t* ui_Image1;
    lv_obj_t* ui_Image2;
    lv_obj_t* ui_Image3;
    lv_obj_t* ui_Image5;
    lv_obj_t* ui_ImageA2;
    lv_obj_t* ui_ImageA1;
    lv_obj_t* ui_ImageA3;


    ui_Image2 = lv_img_create(page);
    lv_img_set_src(ui_Image2, &ui_img_page1_bg_png);
    lv_obj_set_width(ui_Image2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Image2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Image2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    /* 禁止滾動 */
    lv_obj_clear_flag(ui_Image2, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

    ui_Image1 = lv_img_create(page);
    lv_img_set_src(ui_Image1, &ui_img_page1_arc_png);
    lv_obj_set_width(ui_Image1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Image1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Image1, -199);
    lv_obj_set_y(ui_Image1, 164);
    lv_obj_set_align(ui_Image1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_pivot(ui_Image1, 192, 192);
    lv_img_set_angle(ui_Image1, 220);
    /* 禁止滾動 */
    lv_obj_clear_flag(ui_Image1, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

    ui_Image3 = lv_img_create(page);
    lv_img_set_src(ui_Image3, &ui_img_page1_menu_png);
    lv_obj_set_width(ui_Image3, LV_SIZE_CONTENT);   /// 509
    lv_obj_set_height(ui_Image3, LV_SIZE_CONTENT);    /// 260
    lv_obj_set_x(ui_Image3, -150);
    lv_obj_set_y(ui_Image3, 108);
    lv_obj_set_align(ui_Image3, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image3, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    /* 禁止滾動 */
    lv_obj_clear_flag(ui_Image1, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

    /* 建立btn_1 */
    lv_obj_t* btn_1 = lv_btn_create(page);
    lv_obj_t* btn_1_label;

    btn_1_label = lv_label_create(btn_1);
    lv_label_set_text(btn_1_label, "Page2");
    lv_obj_align(btn_1, LV_ALIGN_CENTER, 200, 200);
    //lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);

    lv_obj_add_event_cb(btn_1, page1_btn_1_event_handler, LV_EVENT_ALL, NULL);

    /* 建立btn_2 */
    lv_obj_t* btn_2 = lv_btn_create(page);
    lv_obj_t* btn_2_label;

    btn_2_label = lv_label_create(btn_2);
    lv_label_set_text(btn_2_label, "Page3");
    lv_obj_align(btn_2, LV_ALIGN_CENTER, 300, 200);
    //lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);

    lv_obj_add_event_cb(btn_2, page1_btn_2_event_handler, LV_EVENT_ALL, NULL);

    ui_Panel2 = lv_obj_create(page);
    lv_obj_set_width(ui_Panel2, 250);
    lv_obj_set_height(ui_Panel2, 250);
    lv_obj_set_x(ui_Panel2, 249);
    lv_obj_set_y(ui_Panel2, -37);
    lv_obj_set_align(ui_Panel2, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Panel2, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui_Panel2, true, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Panel2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Panel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Panel2, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Panel2, 3, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Image5 = lv_img_create(ui_Panel2);
    lv_img_set_src(ui_Image5, &ui_img_water_001_png);
    lv_obj_set_width(ui_Image5, LV_SIZE_CONTENT);   /// 300
    lv_obj_set_height(ui_Image5, LV_SIZE_CONTENT);    /// 189
    lv_obj_set_x(ui_Image5, -1);
    lv_obj_set_y(ui_Image5, 79);
    lv_obj_set_align(ui_Image5, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image5, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ImageA2 = lv_img_create(page);
    lv_img_set_src(ui_ImageA2, &ui_img_a2_png);
    lv_obj_set_width(ui_ImageA2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ImageA2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ImageA2, -56);
    lv_obj_set_y(ui_ImageA2, -165);
    lv_obj_set_align(ui_ImageA2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ImageA2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageA2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_opa(ui_ImageA2, LV_OPA_0, LV_PART_MAIN | LV_STATE_DEFAULT);
    /* 禁止滾動 */
    lv_obj_clear_flag(ui_ImageA2, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

    ui_ImageA1 = lv_img_create(page);
    lv_img_set_src(ui_ImageA1, &ui_img_a1_png);
    lv_obj_set_width(ui_ImageA1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ImageA1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ImageA1, -76);
    lv_obj_set_y(ui_ImageA1, -115);
    lv_obj_set_align(ui_ImageA1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ImageA1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageA1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_opa(ui_ImageA1, LV_OPA_0, LV_PART_MAIN | LV_STATE_DEFAULT);
    /* 禁止滾動 */
    lv_obj_clear_flag(ui_ImageA1, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

    ui_ImageA3 = lv_img_create(page);
    lv_img_set_src(ui_ImageA3, &ui_img_a3_png);
    lv_obj_set_width(ui_ImageA3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ImageA3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ImageA3, -51);
    lv_obj_set_y(ui_ImageA3, -159);
    lv_obj_set_align(ui_ImageA3, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ImageA3, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageA3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_opa(ui_ImageA3, LV_OPA_0, LV_PART_MAIN | LV_STATE_DEFAULT);
    /* 禁止滾動 */
    lv_obj_clear_flag(ui_ImageA3, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 8000);
    lv_anim_set_user_data(&PropertyAnimation_0, ui_Image1);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_image_angle);
    lv_anim_set_values(&PropertyAnimation_0, 0, 3600);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 6500);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, LV_ANIM_REPEAT_INFINITE);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_image_angle);
    //lv_pm_obj_anima_smooth_in(Pages1_label_1_label_1, ANIM_DIR_TOP, 0);
    lv_pm_obj_anima_fade_in_out(ui_ImageA2,    0, 1500, 1500,8000, LV_ANIM_REPEAT_INFINITE);
    lv_pm_obj_anima_fade_in_out(ui_ImageA1, 4000, 1500, 1500,8000, LV_ANIM_REPEAT_INFINITE);
    lv_pm_obj_anima_fade_in_out(ui_ImageA3, 8000, 1500, 1500,8000, LV_ANIM_REPEAT_INFINITE);
}

void DeInitPages1(lv_obj_t* page)
{
    // 釋放自己申請的內存
}

void didAppearPages1(lv_obj_t* page)
{
    lv_anim_start(&PropertyAnimation_0);
}
