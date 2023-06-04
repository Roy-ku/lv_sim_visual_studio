/*********************
  *      INCLUDES
  *********************/

#include "pm.h"

/*********************
 *      DEFINES
 *********************/

 /**********************
  *      TYPEDEFS
  **********************/

  /**********************
   *  STATIC PROTOTYPES
   **********************/
/*************************************************************************************************************/
static void _lv_pm_obj_anim_state_look(lv_anim_t* a)
{
    lv_obj_t* obj = (lv_obj_t*)a->user_data;
    _ui_state_modify(obj, LV_STATE_DISABLED, _UI_MODIFY_STATE_ADD);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_HIDDEN);
    _ui_flag_modify(obj, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
}

static void _lv_pm_obj_anim_state_unlook(lv_anim_t* a)
{
    lv_obj_t* obj = (lv_obj_t*)a->user_data;
    _ui_state_modify(obj, LV_STATE_DISABLED, _UI_MODIFY_STATE_REMOVE);
    // _ui_flag_modify(obj, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
}

/*************************************************************************************************************/
void lv_pm_obj_anima_smooth_in(lv_obj_t* targetobject, lv_pm_obj_anim_dir_t dir, int delay)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 200);
    lv_anim_set_user_data(&PropertyAnimation_0, targetobject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_opacity);
    lv_anim_set_values(&PropertyAnimation_0, 0, 255);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_out);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, true);
    lv_anim_set_start_cb(&PropertyAnimation_0, _lv_pm_obj_anim_state_look);
    //lv_anim_set_ready_cb(&PropertyAnimation_0, _lv_pm_obj_anim_state_unlook);
    lv_anim_start(&PropertyAnimation_0);

    lv_anim_t PropertyAnimation_1;
    lv_anim_init(&PropertyAnimation_1);
    lv_anim_set_time(&PropertyAnimation_1, 800);
    lv_anim_set_user_data(&PropertyAnimation_1, targetobject);

    switch (dir)
    {
    case ANIM_DIR_TOP:
        lv_anim_set_custom_exec_cb(&PropertyAnimation_1, _ui_anim_callback_set_y);
        lv_anim_set_values(&PropertyAnimation_1, -100, 0);
        lv_anim_set_get_value_cb(&PropertyAnimation_1, &_ui_anim_callback_get_y);
        break;
    case ANIM_DIR_BOTTOM:
        lv_anim_set_custom_exec_cb(&PropertyAnimation_1, _ui_anim_callback_set_y);
        lv_anim_set_values(&PropertyAnimation_1, 100, 0);
        lv_anim_set_get_value_cb(&PropertyAnimation_1, &_ui_anim_callback_get_y);
        break;
    case ANIM_DIR_LEFT:
        lv_anim_set_custom_exec_cb(&PropertyAnimation_1, _ui_anim_callback_set_x);
        lv_anim_set_values(&PropertyAnimation_1, -100, 0);
        lv_anim_set_get_value_cb(&PropertyAnimation_1, &_ui_anim_callback_get_x);
        break;
    case ANIM_DIR_RIGHT:
        lv_anim_set_custom_exec_cb(&PropertyAnimation_1, _ui_anim_callback_set_x);
        lv_anim_set_values(&PropertyAnimation_1, 100, 0);
        lv_anim_set_get_value_cb(&PropertyAnimation_1, &_ui_anim_callback_get_x);
        break;
    default:
        break;
    }

    lv_anim_set_path_cb(&PropertyAnimation_1, lv_anim_path_ease_out);
    lv_anim_set_delay(&PropertyAnimation_1, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_1, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_1, 0);
    lv_anim_set_early_apply(&PropertyAnimation_1, false);
    //lv_anim_set_start_cb(&PropertyAnimation_1, _lv_pm_obj_anim_state_look);
    lv_anim_set_ready_cb(&PropertyAnimation_1, _lv_pm_obj_anim_state_unlook);
    lv_anim_start(&PropertyAnimation_1);
}

void lv_pm_obj_anima_fade_in(lv_obj_t* targetobject, int delay)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 500);
    lv_anim_set_user_data(&PropertyAnimation_0, targetobject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_opacity);
    lv_anim_set_values(&PropertyAnimation_0, LV_OPA_TRANSP, LV_OPA_COVER);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, true);
    
    lv_anim_set_start_cb(&PropertyAnimation_0, _lv_pm_obj_anim_state_look);
    lv_anim_set_ready_cb(&PropertyAnimation_0, _lv_pm_obj_anim_state_unlook);

    lv_anim_start(&PropertyAnimation_0);
}

void lv_pm_obj_anima_fade_out(lv_obj_t* targetobject, int delay)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 500);
    lv_anim_set_user_data(&PropertyAnimation_0, targetobject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_opacity);
    lv_anim_set_values(&PropertyAnimation_0, LV_OPA_COVER, LV_OPA_TRANSP);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, true);

    lv_anim_set_start_cb(&PropertyAnimation_0, _lv_pm_obj_anim_state_look);
    lv_anim_set_ready_cb(&PropertyAnimation_0, _lv_pm_obj_anim_state_unlook);

    lv_anim_start(&PropertyAnimation_0);
}

/**
 * @brief  物件閃爍效果
 * @param targetobject 目標物件 
 * @param delay 延遲(第一次播放動畫前的延遲)
 * @param time 動畫時長
 * @param playback_time 回放動畫時長
 * @param repeat_delay 動畫再次播放的延遲
 * @param repeat_count 播放次數 ( `LV_ANIM_REPEAT_INFINITE` for infinite repetition. 0: to disable repetition.)
*/
void lv_pm_obj_anima_fade_in_out(lv_obj_t* targetobject, int delay,int time ,int playback_time,int repeat_delay, int repeat_count)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, time); //1000
    lv_anim_set_user_data(&PropertyAnimation_0, targetobject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_opacity);
    lv_anim_set_values(&PropertyAnimation_0, 0, 255);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, playback_time);//
    lv_anim_set_playback_delay(&PropertyAnimation_0, 500);
    lv_anim_set_repeat_count(&PropertyAnimation_0, repeat_count); //LV_ANIM_REPEAT_INFINITE
    lv_anim_set_repeat_delay(&PropertyAnimation_0, repeat_delay);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_opacity);
    lv_anim_start(&PropertyAnimation_0);
}

void lv_pm_obj_anima_none_in(lv_obj_t* targetobject)
{
    _ui_flag_modify(targetobject, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
}

void lv_pm_obj_anima_none_out(lv_obj_t* targetobject)
{
    _ui_flag_modify(targetobject, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
}

void lv_custom_obj_jump_anim(lv_obj_t* targetobject, int delay)
{
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 250);
    lv_anim_set_user_data(&PropertyAnimation_0, targetobject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_y);
    lv_anim_set_values(&PropertyAnimation_0, 0, -20);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 100);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_y);

    //lv_anim_set_start_cb(&PropertyAnimation_0, _lv_pm_obj_anim_state_look);
    //lv_anim_set_ready_cb(&PropertyAnimation_0, _lv_pm_obj_anim_state_unlook);
    lv_anim_start(&PropertyAnimation_0);
}

/*************************************************************************************************************/

