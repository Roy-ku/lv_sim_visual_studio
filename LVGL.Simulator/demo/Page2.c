/* Page 2 */
#include "Page.h"

static void page2_btn_1_event_handler(lv_event_t* e);
static void page2_btn_2_event_handler(lv_event_t* e);
static void Style_Set_label_1(lv_obj_t* obj);
static bool page2_btn_2_toggle;
static lv_point_t point;
lv_obj_t* ui_Panel2;
lv_anim_t PropertyAnimation_0;
bool look = false;
lv_pm_open_options_t options2 =
{
  .animation = LV_PM_ANIMA_NONE,
  .target = LV_PM_TARGET_SELF,
  //.direction = LV_PM_ANIMA_TOP /*暫無功能*/
};

void Y1_Down_Animation(lv_obj_t* TargetObject, int delay)
{
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 100);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_y);
    lv_anim_set_values(&PropertyAnimation_0, 0, 200);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_out);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_y);
    lv_anim_start(&PropertyAnimation_0);
}
void Y1_TOP_Animation(lv_obj_t* TargetObject, int delay)
{
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 100);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_y);
    lv_anim_set_values(&PropertyAnimation_0, 0, -200);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_out);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_y);
    lv_anim_start(&PropertyAnimation_0);
}
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

static void page2_btn_1_event_handler(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        lv_pm_open_page(1, &options2);
    }
    break;
    default:
        break;
    }
}
static void page2_btn_2_event_handler(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t* obj = lv_event_get_target(e);
    lv_obj_t* obj2 = (lv_obj_t*)e->user_data;
    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        if (page2_btn_2_toggle == false)
        {
            page2_btn_2_toggle = true;
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xe60012), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj2, " Disconnect");
        }
        else
        {
            page2_btn_2_toggle = false;
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x1ac000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj2, " Connect");
        }
    }
    break;
    default:
        break;
    }
}

static void gesture_dir_event_cb(lv_event_t* e)
{
    //lv_obj_t* screen = lv_event_get_current_target(e);
    lv_indev_wait_release(lv_indev_get_act());
    lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
    switch (dir) {
    case LV_DIR_LEFT:
        LV_LOG_USER("LV_DIR_LEFT\r\n");
        break;
    case LV_DIR_RIGHT:
        LV_LOG_USER("LV_DIR_RIGHT\r\n");
        break;
    case LV_DIR_TOP:
        LV_LOG_USER("LV_DIR_TOP\r\n");
        if (look == true)
        {
            Y1_TOP_Animation(ui_Panel2, 0);
            look = false;
        }
        break;
    case LV_DIR_BOTTOM:
        LV_LOG_USER("LV_DIR_BOTTOM\r\n");
        if (look == false && point.y<20)
        {
            Y1_Down_Animation(ui_Panel2, 0);
            look = true;
        }
        break;
    }
}

static void get_ponit_event_cb(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code)
    {
    case LV_EVENT_PRESSED:
    {

        lv_indev_get_point(lv_indev_get_act(), &point);
        lv_log("X:%d, Y:%d\r\n", point.x, point.y);
    }
    break;
    default:
        break;
    }
}

void InitPages2(lv_obj_t* page)
{
    lv_obj_t* page1 = lv_obj_create(page);
    lv_obj_align(page1, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_size(page1, lv_disp_get_hor_res(NULL), lv_disp_get_ver_res(NULL));
    lv_obj_set_style_radius(page1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(page1, 0, LV_PART_MAIN | LV_STATE_DEFAULT); //設定邊框
    /* 禁止滾動 */
    lv_obj_clear_flag(page1, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

    static lv_style_t style_page = { 0 };
    if (style_page.prop_cnt > 1)
        lv_style_reset(&style_page);
    else
        lv_style_init(&style_page);
    lv_style_set_bg_color(&style_page, lv_color_make(0xe4, 0xc3, 0x21));
    lv_style_set_bg_opa(&style_page, 255);
    lv_obj_add_style(page1, &style_page, LV_PART_MAIN | LV_STATE_DEFAULT);

    /* 建立label_1 */
    lv_obj_t* TestPages_label_1_label_1 = lv_label_create(page1);
    lv_obj_set_pos(TestPages_label_1_label_1, 400, 80);
    Style_Set_label_1(TestPages_label_1_label_1);
    lv_obj_align(TestPages_label_1_label_1, LV_ALIGN_CENTER, 0, -10);
    lv_obj_set_size(TestPages_label_1_label_1, 240, 40);
    lv_obj_set_scrollbar_mode(TestPages_label_1_label_1, LV_SCROLLBAR_MODE_OFF);
    //lv_obj_set_style_text_font(TestPages_label_1_label_1, &NotoSansTC_Regular_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_label_set_long_mode(TestPages_label_1_label_1, LV_LABEL_LONG_WRAP);
    lv_label_set_text(TestPages_label_1_label_1, "Page2");

    /* 建立btn_1 */
    lv_obj_t* btn_1 = lv_btn_create(page1);
    lv_obj_t* btn_1_label;

    btn_1_label = lv_label_create(btn_1);
    lv_label_set_text(btn_1_label, "page1");
    lv_obj_align(btn_1, LV_ALIGN_CENTER, 0, 180);
    //lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_add_event_cb(btn_1, page2_btn_1_event_handler, LV_EVENT_ALL, NULL);

    /* 建立btn_2 */
    lv_obj_t* btn_2 = lv_btn_create(page1);
    lv_obj_t* btn_2_label;
    page2_btn_2_toggle = false;
    lv_obj_set_size(btn_2, 125, 30);
    lv_obj_align(btn_2, LV_ALIGN_CENTER, 0, 40);
    lv_obj_set_style_bg_color(btn_2, lv_color_hex(0x1ac000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(btn_2, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

    btn_2_label = lv_label_create(btn_2);
    lv_label_set_text(btn_2_label, "Connect");
    lv_obj_center(btn_2_label);
    lv_obj_add_event_cb(btn_2, page2_btn_2_event_handler, LV_EVENT_ALL, btn_2_label);

    lv_obj_t* btn_2_label2;
    ui_Panel2 = lv_obj_create(lv_scr_act());
    lv_obj_set_width(ui_Panel2, 350);
    lv_obj_set_height(ui_Panel2, 200);
    lv_obj_set_x(ui_Panel2, 0);
    lv_obj_set_y(ui_Panel2, -200);
    lv_obj_set_align(ui_Panel2, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_Panel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Panel2, lv_color_hex(0x0AD9ED), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel2, LV_OPA_50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT); //設定邊框
    btn_2_label2 = lv_label_create(ui_Panel2);
    lv_label_set_text(btn_2_label2, "control center");
    lv_obj_set_align(btn_2_label2, LV_ALIGN_TOP_MID);
    lv_obj_center(btn_2_label2);

    lv_obj_add_event_cb(lv_scr_act(), gesture_dir_event_cb, LV_EVENT_GESTURE, NULL); // 新增手勢事件
    lv_obj_add_event_cb(page1, get_ponit_event_cb, LV_EVENT_PRESSED, NULL); // 取得觸摸座標事件

    look = false;
}

void DeInitPages2(lv_obj_t* page)
{
    //釋放自己申請的內存
    lv_obj_remove_event_cb(lv_scr_act(), gesture_dir_event_cb); // 移除手勢事件
    lv_obj_del(ui_Panel2);
}
