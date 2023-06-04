#include "anima.h"
//#include "./SLgenerated.c"

typedef struct _lv_pm_anima_data {
    lv_pm_page_t* pm_page;
    lv_pm_anima_complete_cb cb;
    lv_pm_open_options_t options;
} lv_pm_anima_data;

static void _anime_origin_hidden(void)
{
    lv_obj_set_width(lv_pm_origin_panel, 0);
    lv_obj_set_height(lv_pm_origin_panel, 0);
}

static void _anime_origin_sohw(void)
{
    lv_pm_origin_reset();
}

static void translateX_anima_cb(void* var, int32_t v)
{
    lv_obj_set_x(var, v);
}

static void translateY_anima_cb(void* var, int32_t v)
{
    lv_obj_set_y(var, v);
}

static void anima_ready_cb(lv_anim_t* anim)
{
    lv_pm_anima_data* cb_data = (lv_pm_anima_data*)anim->user_data;
    cb_data->cb(cb_data->pm_page, cb_data->options);
    free(anim->user_data);
}

/**
----------------------------------------------------------------------------------------------------------
  slide animation
----------------------------------------------------------------------------------------------------------
*/

static void _pm_slide_appear(lv_pm_anima_data* anima_data)
{
    lv_anim_t PropertyAnimation_0 = { 0 };
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_user_data(&PropertyAnimation_0, (void*)anima_data);
    lv_anim_set_var(&PropertyAnimation_0, anima_data->pm_page->page);

    switch (anima_data->options.animation)
    {
    case LV_PM_ANIMA_SLIDE_LEFT:
        lv_anim_set_values(&PropertyAnimation_0, -1000, 0);
        break;
    case LV_PM_ANIMA_SLIDE_RIGHT:
        lv_anim_set_values(&PropertyAnimation_0, 1000, 0);
        break;
    default:
        lv_anim_set_values(&PropertyAnimation_0, -1000, 0);
        break;
    }

    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_out);
    lv_anim_set_time(&PropertyAnimation_0, 500);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_exec_cb(&PropertyAnimation_0, translateX_anima_cb);
    lv_anim_set_ready_cb(&PropertyAnimation_0, anima_ready_cb);
    lv_anim_start(&PropertyAnimation_0);

    /* 用於隱藏 lv_pm_obj_origin */
    lv_anim_t PropertyAnimation_1 = { 0 };
    lv_anim_init(&PropertyAnimation_1);
    lv_anim_set_time(&PropertyAnimation_1, 500);
    lv_anim_set_early_apply(&PropertyAnimation_1, false);
    lv_anim_set_ready_cb(&PropertyAnimation_1, (void*)_anime_origin_hidden);
    lv_anim_start(&PropertyAnimation_1);
}

static void _pm_slide_disAppear(lv_pm_anima_data* anima_data)
{
    lv_anim_t PropertyAnimation_0 = { 0 };

    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_user_data(&PropertyAnimation_0, (void*)anima_data);
    lv_anim_set_var(&PropertyAnimation_0, anima_data->pm_page->page);

    switch (anima_data->options.animation)
    {
    case LV_PM_ANIMA_SLIDE_LEFT:
        lv_anim_set_values(&PropertyAnimation_0, 0, -1000);
        break;
    case LV_PM_ANIMA_SLIDE_RIGHT:
        lv_anim_set_values(&PropertyAnimation_0, 0, 1000);
        break;
    default:
        lv_anim_set_values(&PropertyAnimation_0, 0, -1000);
        break;
    }

    lv_anim_set_time(&PropertyAnimation_0, 500);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_exec_cb(&PropertyAnimation_0, translateX_anima_cb);
    lv_anim_set_ready_cb(&PropertyAnimation_0, anima_ready_cb);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_out);
    lv_anim_start(&PropertyAnimation_0);
}

/** ------------------------------------slide animation end-------------------------------------------- */

/**
----------------------------------------------------------------------------------------------------------
  bubble animation
----------------------------------------------------------------------------------------------------------
*/
static void _pm_bubble_appear(lv_pm_anima_data* anima_data)
{
    lv_anim_t PropertyAnimation_0 = { 0 };
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 500);
    lv_anim_set_user_data(&PropertyAnimation_0, lv_pm_origin_dot);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_width);
    lv_anim_set_values(&PropertyAnimation_0, 0, 1000);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_in);
    lv_anim_set_delay(&PropertyAnimation_0,   0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 300);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 500);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 500);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_width);
    lv_anim_start(&PropertyAnimation_0);
    lv_anim_t PropertyAnimation_1 = { 0 };
    lv_anim_init(&PropertyAnimation_1);
    lv_anim_set_time(&PropertyAnimation_1, 500);
    lv_anim_set_user_data(&PropertyAnimation_1, lv_pm_origin_dot);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_1, _ui_anim_callback_set_height);
    lv_anim_set_values(&PropertyAnimation_1, 0, 1000);
    lv_anim_set_path_cb(&PropertyAnimation_1, lv_anim_path_ease_in);
    lv_anim_set_delay(&PropertyAnimation_1,  0);
    lv_anim_set_playback_time(&PropertyAnimation_1, 300);
    lv_anim_set_playback_delay(&PropertyAnimation_1, 500);
    lv_anim_set_repeat_count(&PropertyAnimation_1, 1);
    lv_anim_set_repeat_delay(&PropertyAnimation_1, 500);
    lv_anim_set_early_apply(&PropertyAnimation_1, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_1, &_ui_anim_callback_get_height);
    lv_anim_set_ready_cb(&PropertyAnimation_1, (void*)_anime_origin_hidden);
    lv_anim_start(&PropertyAnimation_1);

    lv_anim_t PropertyAnimation_2 = { 0 };
    lv_anim_init(&PropertyAnimation_2);
    lv_anim_set_time(&PropertyAnimation_2, 500);
    lv_anim_set_user_data(&PropertyAnimation_2, (void*)anima_data);
    lv_anim_set_delay(&PropertyAnimation_2, 0);
    lv_anim_set_var(&PropertyAnimation_2, anima_data->pm_page->page);
    lv_anim_set_early_apply(&PropertyAnimation_2, false);
    lv_anim_set_ready_cb(&PropertyAnimation_2, anima_ready_cb);
    lv_anim_start(&PropertyAnimation_2);
}

static void _pm_bubble_disAppear(lv_pm_anima_data* anima_data)
{
    lv_anim_t PropertyAnimation_0 = { 0 };
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 500);
    lv_anim_set_user_data(&PropertyAnimation_0, (void*)anima_data);
    lv_anim_set_delay(&PropertyAnimation_0, 0);
    lv_anim_set_var(&PropertyAnimation_0, anima_data->pm_page->page);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_ready_cb(&PropertyAnimation_0, anima_ready_cb);
    lv_anim_start(&PropertyAnimation_0);
}
/** ------------------------------------bubble animation end-------------------------------------------- */

/**
----------------------------------------------------------------------------------------------------------
  fade in / fade out animation
----------------------------------------------------------------------------------------------------------
*/
static void _pm_fade_appear(lv_pm_anima_data* anima_data)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 600);
    lv_anim_set_user_data(&PropertyAnimation_0, anima_data->pm_page->page);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_opacity);
    lv_anim_set_values(&PropertyAnimation_0, LV_OPA_0, LV_OPA_100);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_opacity);
    lv_anim_start(&PropertyAnimation_0);

    lv_anim_t PropertyAnimation_1 = { 0 };
    lv_anim_init(&PropertyAnimation_1);
    lv_anim_set_time(&PropertyAnimation_1, 600);
    lv_anim_set_user_data(&PropertyAnimation_1, (void*)anima_data);
    lv_anim_set_delay(&PropertyAnimation_1, 0);
    lv_anim_set_var(&PropertyAnimation_1, anima_data->pm_page->page);
    lv_anim_set_early_apply(&PropertyAnimation_1, false);
    lv_anim_set_ready_cb(&PropertyAnimation_1, anima_ready_cb);
    lv_anim_start(&PropertyAnimation_1);

    /* 用於隱藏 lv_pm_obj_origin */
    lv_anim_t PropertyAnimation_2 = { 0 };
    lv_anim_init(&PropertyAnimation_2);
    lv_anim_set_time(&PropertyAnimation_2, 600);
    lv_anim_set_early_apply(&PropertyAnimation_2, false);
    lv_anim_set_ready_cb(&PropertyAnimation_2, (void*)_anime_origin_hidden);
    lv_anim_start(&PropertyAnimation_2);
}

static void _pm_fade_disAppear(lv_pm_anima_data* anima_data)
{
    /* 慎用，如果進場和離場都使用淡入但出效果，非常吃性能!!! */
    // lv_anim_t PropertyAnimation_0;
    // lv_anim_init(&PropertyAnimation_0);
    // lv_anim_set_time(&PropertyAnimation_0, 600);
    // lv_anim_set_user_data(&PropertyAnimation_0, anima_data->pm_page->page);
    // lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_opacity);
    // lv_anim_set_values(&PropertyAnimation_0, LV_OPA_100, LV_OPA_0);
    // lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    // lv_anim_set_early_apply(&PropertyAnimation_0, false);
    // lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_opacity);
    // lv_anim_start(&PropertyAnimation_0);

    lv_anim_t PropertyAnimation_1 = { 0 };
    lv_anim_init(&PropertyAnimation_1);
    lv_anim_set_time(&PropertyAnimation_1, 10);
    lv_anim_set_user_data(&PropertyAnimation_1, (void*)anima_data);
    lv_anim_set_delay(&PropertyAnimation_1, 0);
    lv_anim_set_var(&PropertyAnimation_1, anima_data->pm_page->page);
    lv_anim_set_early_apply(&PropertyAnimation_1, false);
    lv_anim_set_ready_cb(&PropertyAnimation_1, anima_ready_cb);
    lv_anim_start(&PropertyAnimation_1);
}
/** ------------------------------------fade in / fade out animation end-------------------------------------------- */
/* 進場 */
void _pm_anima_appear(lv_pm_page_t* pm_page, lv_pm_open_options_t* behavior, lv_pm_anima_complete_cb cb)
{
    if (behavior == NULL || behavior->animation == LV_PM_ANIMA_NONE) {
        _anime_origin_hidden();
        cb(pm_page, *behavior);
        LV_LOG_USER("LV_PM_ANIMA_NONE.\r\n");
        return;
    }

    lv_pm_anima_data* anima_data = (lv_pm_anima_data*)malloc(sizeof(lv_pm_anima_data));
    if (anima_data == NULL) {
        _anime_origin_hidden();
        cb(pm_page, *behavior);
        LV_LOG_USER("anima_data is NULL.\r\n");
        return;
    }

    anima_data->pm_page = pm_page;
    anima_data->cb = cb;
    anima_data->options = *behavior;

    _anime_origin_sohw();
    switch (behavior->animation)
    {
    case LV_PM_ANIMA_SLIDE_LEFT:
        _pm_slide_appear(anima_data);
        break;
    case LV_PM_ANIMA_SLIDE_RIGHT:
        _pm_slide_appear(anima_data);
        break;
    case LV_PM_ANIMA_BUBBLE:
        _pm_bubble_appear(anima_data);
        break;
    case LV_PM_ANIMA_FADE:
        _pm_fade_appear(anima_data);
        break;
    default:
        LV_LOG_USER("Appear No such animation, so changed to default animation.\r\n");
        _anime_origin_hidden();
        cb(pm_page, *behavior);
        break;
    }
}

/* 離場 */
void _pm_anima_disAppear(lv_pm_page_t* pm_page, lv_pm_open_options_t* behavior, lv_pm_anima_complete_cb cb)
{
    /* 先移出當前畫面所有的動畫效果 */
    lv_anim_del_all();

    if (behavior == NULL || behavior->animation == LV_PM_ANIMA_NONE) {
        cb(pm_page, *behavior);
        LV_LOG_USER("LV_PM_ANIMA_NONE.\r\n");
        return;
    }

    lv_pm_anima_data* anima_data = (lv_pm_anima_data*)malloc(sizeof(lv_pm_anima_data));
    if (anima_data == NULL) {
        cb(pm_page, *behavior);
        LV_LOG_USER("anima_data is NULL.\r\n");
        return;
    }

    anima_data->pm_page = pm_page;
    anima_data->cb = cb;
    anima_data->options = *behavior;

    switch (behavior->animation)
    {
    case LV_PM_ANIMA_SLIDE_LEFT:
        _pm_slide_disAppear(anima_data);
        break;
    case LV_PM_ANIMA_SLIDE_RIGHT:
        _pm_slide_disAppear(anima_data);
        break;
    case LV_PM_ANIMA_BUBBLE:
        _pm_bubble_disAppear(anima_data);
        break;
    case LV_PM_ANIMA_FADE:
        _pm_fade_disAppear(anima_data);
        break;
    default:
        LV_LOG_USER("DisAppear No such animation, so changed to default animation.\r\n");
        cb(pm_page, *behavior);
        break;
    }
}
