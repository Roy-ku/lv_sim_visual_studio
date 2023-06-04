#include "pm.h"
#include "anima.h"
#include "pm_utils.h"

lv_obj_t* lv_pm_origin_panel;
lv_obj_t* lv_pm_origin_dot;
uint8_t lv_pm_history_len;

lv_pm_page_t* lv_pm_router[LV_PM_PAGE_NUM];
uint8_t lv_pm_history[LV_PM_PAGE_NUM];

lv_pm_open_options_t options =
{
  .animation = LV_PM_ANIMA_NONE,
  .target = LV_PM_TARGET_SELF,
  //.direction = LV_PM_ANIMA_TOP /*暫無功能*/
};

void lv_pm_origin_reset(void);

static void _disAppear_complete_cb(lv_pm_page_t* pm_page, lv_pm_open_options_t options);     /* 離場完成回調  */
static void _appear_will_cb(lv_pm_page_t* pm_page, lv_pm_open_options_t options);                     /* 即將進場回調 */
static void _appear_complete_cb(lv_pm_page_t* pm_page, lv_pm_open_options_t options);          /* 進場完成回調 */
static void  lv_pm_obj_origin_event_cb(lv_event_t* e);
static void lv_pm_custom_log_cb(const char* dsc);

/** ------------------------------------pm event callback start-------------------------------------------- */
/* 即將進場回調 */
static void _appear_will_cb(lv_pm_page_t* pm_page, lv_pm_open_options_t options)
{
    /* 如果轉場動畫類型，對象是Page本身時需要調用  lv_obj_clear_flag(pm_page->page, LV_OBJ_FLAG_HIDDEN); */
    if ((options.animation == LV_PM_ANIMA_SLIDE_LEFT) || (options.animation == LV_PM_ANIMA_SLIDE_RIGHT) || (options.animation == LV_PM_ANIMA_FADE))
    {
        /* 此處動畫為LV_PM_ANIMA_FADE時。需要先把頁面透明度設為0，否則會閃爍一下 */
        if(options.animation == LV_PM_ANIMA_FADE)
        {
            lv_obj_set_style_opa(pm_page->page, LV_OPA_0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        lv_obj_clear_flag(pm_page->page, LV_OBJ_FLAG_HIDDEN);
    }
}

/* 進場完成回調 */
static void _appear_complete_cb(lv_pm_page_t* pm_page, lv_pm_open_options_t options)
{
    if (pm_page->didAppear) {
        pm_page->didAppear(pm_page->page);
    }
    lv_obj_clear_flag(pm_page->page, LV_OBJ_FLAG_HIDDEN);
}

/*  離場完成回調  */
static void _disAppear_complete_cb(lv_pm_page_t* pm_page, lv_pm_open_options_t options)
{
    if (pm_page->didDisappear)
    {
        pm_page->didDisappear(pm_page->page);
    }
    if (options.target == LV_PM_TARGET_SELF || options.target == NULL)
    {
        pm_page->unLoad(pm_page->page);
        lv_obj_clean(pm_page->page);
    }
    lv_obj_add_flag(pm_page->page, LV_OBJ_FLAG_HIDDEN);
}

static void  lv_pm_obj_origin_event_cb(lv_event_t* e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t* target = lv_event_get_target(e);
    LV_LOG_USER("event_code = %d\r\n", event_code);
    if (event_code == LV_EVENT_CLICKED) {
        static uint32_t double_click_time_old = 0; // 初始化Tick
        uint32_t double_click_time_new = lv_tick_get(); // 取得目前Tick

        /* 判斷新舊Tick的間隔是否符合條件 */
        if (double_click_time_new - double_click_time_old < LV_PM_DOUBLE_CLICK_TIME_INTERVAL)
        {
            lv_pm_exit_sleepmode();
        }
        double_click_time_old = double_click_time_new; // 更新舊Tick
    }
}

static void lv_pm_custom_log_cb(const char* dsc)
{
    bsp_Log_Debug("[lvgl] %s", dsc);
}

/** ------------------------------------pm event callback end-------------------------------------------- */

void lv_pm_enter_sleepmode(void)
{
    LV_LOG_USER("enter_sleepmode\r\n");
    //bsp_LCD_Backlight_OFF();
    // slv_obj_set_style_bg_opa(lv_pm_origin_panel, LV_OPA_100, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_width(lv_pm_origin_panel, LV_PM_ORIGIN_PANEL_WIDTH);
    lv_obj_set_height(lv_pm_origin_panel, LV_PM_ORIGIN_PANEL_HEIGHT);
    lv_obj_add_event_cb(lv_pm_origin_panel, lv_pm_obj_origin_event_cb, LV_EVENT_CLICKED, NULL);
}

void lv_pm_exit_sleepmode(void)
{
    LV_LOG_USER("exitSleepmode\r\n");
    //bsp_LCD_Backlight_ON();
    // lv_obj_set_style_bg_opa(lv_pm_origin_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_width(lv_pm_origin_panel, 0);
    lv_obj_set_height(lv_pm_origin_panel, 0);
    lv_obj_remove_event_cb(lv_pm_origin_panel, lv_pm_obj_origin_event_cb);
}

void lv_pm_origin_create(void)
{
    lv_pm_origin_panel = lv_obj_create(lv_layer_top());
    /* 禁止滾動 */
    lv_obj_clear_flag(lv_pm_origin_panel, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);
    lv_obj_set_width(lv_pm_origin_panel, LV_PM_ORIGIN_PANEL_WIDTH);
    lv_obj_set_height(lv_pm_origin_panel, LV_PM_ORIGIN_PANEL_HEIGHT);
    lv_obj_set_style_radius(lv_pm_origin_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_align(lv_pm_origin_panel, LV_ALIGN_CENTER);
    lv_obj_set_style_bg_color(lv_pm_origin_panel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(lv_pm_origin_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(lv_pm_origin_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT); //設定邊框

    lv_pm_origin_dot = lv_obj_create(lv_pm_origin_panel);
    /* 禁止滾動 */
    lv_obj_clear_flag(lv_pm_origin_dot, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

    lv_obj_set_width(lv_pm_origin_dot, 0);
    lv_obj_set_height(lv_pm_origin_dot, 0);
    lv_obj_set_align(lv_pm_origin_dot, LV_ALIGN_CENTER);
    lv_obj_clear_flag(lv_pm_origin_dot, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(lv_pm_origin_dot, 1000, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(lv_pm_origin_dot, lv_color_hex(0xFFFFFF), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(lv_pm_origin_dot, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(lv_pm_origin_dot, lv_color_hex(0xFFA000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(lv_pm_origin_dot, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(lv_pm_origin_dot, 1000, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(lv_pm_origin_dot, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
}

void lv_pm_origin_reset(void)
{
    lv_obj_set_width(lv_pm_origin_panel, LV_PM_ORIGIN_PANEL_WIDTH);
    lv_obj_set_height(lv_pm_origin_panel, LV_PM_ORIGIN_PANEL_HEIGHT);
    lv_obj_set_align(lv_pm_origin_panel, LV_ALIGN_CENTER);

    lv_obj_set_width(lv_pm_origin_dot, 0);
    lv_obj_set_height(lv_pm_origin_dot, 0);
    lv_obj_set_align(lv_pm_origin_dot, LV_ALIGN_CENTER);
}

uint8_t lv_pm_init(void)
{
    lv_pm_history_len = 0;
    for (uint8_t i = 0; i < LV_PM_PAGE_NUM; i++)
    {
        lv_pm_router[i] = 0;
    }

    // lv_obj_t* screen = lv_scr_act();
    // /* 禁止滾動 */
    // lv_obj_clear_flag(screen, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

#if (LV_PM_UNITE_STYLE)
    static lv_style_t lv_pm_style = { 0 };
    lv_style_init(&lv_pm_style);
    //lv_style_set_bg_color(&lv_pm_style, lv_color_black());
    lv_style_set_bg_color(&lv_pm_style, lv_color_hex(LV_PM_UNITE_STYLE_COLOR));
    lv_style_set_border_width(&lv_pm_style, 0);
    lv_style_set_pad_all(&lv_pm_style, 0);
    lv_style_set_radius(&lv_pm_style, 0);
    lv_style_set_shadow_width(&lv_pm_style, 0);
    lv_obj_add_style(lv_scr_act(), &lv_pm_style, 0);
#endif

#if (LV_LOG_PRINTF != 1)
    lv_log_register_print_cb(lv_pm_custom_log_cb);
#endif

    lv_pm_origin_create();
    return LV_PM_STATE_OK;
}

lv_pm_page_t* lv_pm_create_page(uint8_t id)
{
    if (id == LV_PM_PAGE_NUM)
    {
        lv_log("LV_PM_PAGE_NUM is over.\r\n");
        return NULL;
    }

    lv_pm_page_t* pm_page = (lv_pm_page_t*)malloc(sizeof(lv_pm_page_t));
    if (pm_page == NULL) {
        return NULL;
    }
    memset(pm_page, 0, sizeof(lv_pm_page_t));

    lv_pm_router[id] = pm_page;
    lv_obj_t* page = lv_obj_create(lv_scr_act());
    // reset style. border radius etc...
    lv_pm_reset_style(page);
    lv_obj_add_flag(page, LV_OBJ_FLAG_HIDDEN);
    lv_coord_t width = lv_disp_get_hor_res(NULL);
    lv_coord_t height = lv_disp_get_ver_res(NULL);
    lv_obj_set_width(page, width);
    lv_obj_set_height(page, height);
    lv_obj_set_align(page, LV_ALIGN_CENTER);
    lv_obj_set_style_border_width(page, 0, LV_PART_MAIN | LV_STATE_DEFAULT); //設定邊框
    pm_page->page = page;
    return pm_page;
}

uint8_t lv_pm_open_page(uint8_t id, lv_pm_open_options_t* behavior)
{
    if (lv_pm_router[id] == 0) {
        LV_LOG_INFO("lv_pm is no page.\r\n");
        return LV_PM_STATE_NOPAGE;
    }

    if (lv_pm_history_len == LV_PM_PAGE_NUM) {
        LV_LOG_INFO("lv_pm history len is Full.\r\n");
        return LV_PM_STATE_PAGEFULL;
    }

    lv_pm_history[lv_pm_history_len] = id;
    lv_pm_page_t* pm_page = lv_pm_router[id];
    lv_obj_t* page = pm_page->page;
    if (behavior) {
        pm_page->_options = *behavior;
    }

    /* 重置PM樣式 */
    lv_pm_reset_style(page);

    if (lv_pm_history_len > 0)
    {
        uint8_t pid = lv_pm_history[lv_pm_history_len - 1];
        lv_pm_page_t* prev_pm_page = lv_pm_router[pid];
        lv_obj_t* prev_page = prev_pm_page->page;

        /* 畫面完成離場 ，用戶回調在 _disAppear_complete_cb 中 */
        _pm_anima_disAppear(prev_pm_page, &pm_page->_options, _disAppear_complete_cb);
    }

    /* 畫面載入 */
    pm_page->onLoad(page);

    /* 畫面即將進場 */
    if (pm_page->willAppear) {
        pm_page->willAppear(page);
    }
    _appear_will_cb(pm_page, pm_page->_options);

    /* 畫面完成進場 用戶回調在 _appear_complete_cb 中 */
    _pm_anima_appear(pm_page, &pm_page->_options, _appear_complete_cb);

    if (behavior && behavior->target == LV_PM_TARGET_SELF)
    {
        if (lv_pm_history_len == 0)
        {
            lv_pm_history_len++;
        }
        else
        {
            lv_pm_history[lv_pm_history_len - 1] = lv_pm_history[lv_pm_history_len];
        }
    }
    else {
        lv_pm_history_len++;
    }
    LV_LOG_USER("lv_pm_history_len = %d\r\n", lv_pm_history_len);
    return LV_PM_STATE_OK;
}

