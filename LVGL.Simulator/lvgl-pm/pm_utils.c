#include "pm_utils.h"

void lv_pm_reset_style(lv_obj_t* obj)
{
    lv_obj_set_style_border_width(obj, 0, LV_STATE_DEFAULT);
    lv_obj_set_style_radius(obj, 0, LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(obj, 0, LV_STATE_DEFAULT);

    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
    /* 禁止滾動 */
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN);

    // 透明背景 
    lv_obj_remove_style_all(obj);
    lv_obj_set_size(obj, LV_PCT(100), LV_PCT(100));
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_opa(obj, LV_OPA_0, 0);
    lv_obj_align(obj, LV_ALIGN_CENTER, 0, 0);
}
