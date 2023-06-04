#ifndef __SLGENERATED_H_
#define __SLGENERATED_H_
#ifdef __cplusplus
extern "C" {
#endif

//#include "gui_guider.h"
#include "lvgl.h"

void _ui_anim_callback_set_image_zoom(lv_anim_t* a, int32_t v);
int32_t _ui_anim_callback_get_image_zoom(lv_anim_t* a);
void _ui_anim_callback_set_image_angle(lv_anim_t* a, int32_t v);
int32_t _ui_anim_callback_get_image_angle(lv_anim_t* a);
void _ui_anim_callback_set_opacity(lv_anim_t *a, int32_t v);
int32_t _ui_anim_callback_get_opacity(lv_anim_t *a);
void _ui_anim_callback_set_x(lv_anim_t *a, int32_t v);
int32_t _ui_anim_callback_get_x(lv_anim_t *a);
void _ui_anim_callback_set_y(lv_anim_t *a, int32_t v);
int32_t _ui_anim_callback_get_y(lv_anim_t *a);
void _ui_anim_callback_set_width(lv_anim_t * a, int32_t v);
int32_t _ui_anim_callback_get_width(lv_anim_t * a);
void _ui_anim_callback_set_height(lv_anim_t *a, int32_t v);
int32_t _ui_anim_callback_get_height(lv_anim_t *a);

#define _UI_MODIFY_STATE_ADD 0
#define _UI_MODIFY_STATE_REMOVE 1
#define _UI_MODIFY_STATE_TOGGLE 2
void _ui_state_modify(lv_obj_t *target, int32_t state, int value);

#define _UI_MODIFY_FLAG_ADD 0
#define _UI_MODIFY_FLAG_REMOVE 1
#define _UI_MODIFY_FLAG_TOGGLE 2
void _ui_flag_modify(lv_obj_t *target, int32_t flag, int value);

#define _UI_SLIDER_PROPERTY_VALUE 0
#define _UI_SLIDER_PROPERTY_VALUE_WITH_ANIM 1
void _ui_slider_set_property(lv_obj_t * target, int id, int val);

#define _UI_TEMPORARY_STRING_BUFFER_SIZE 32
#define _UI_BAR_PROPERTY_VALUE 0
#define _UI_BAR_PROPERTY_VALUE_WITH_ANIM 1
void _ui_bar_set_property(lv_obj_t * target, int id, int val);
void _ui_slider_set_text_value(lv_obj_t * trg, lv_obj_t * src, char * prefix, char * postfix);
void _ui_label_set_text_value(lv_obj_t *trg, int value);
#ifdef __cplusplus
}
#endif
#endif /* EVENT_CB_H_ */
