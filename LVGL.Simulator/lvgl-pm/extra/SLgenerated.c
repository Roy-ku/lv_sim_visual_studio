#include "./SLgenerated.h"

void _ui_anim_callback_set_image_zoom(lv_anim_t* a, int32_t v)
{
    lv_img_set_zoom((lv_obj_t*)a->user_data, v);
}

int32_t _ui_anim_callback_get_image_zoom(lv_anim_t* a)
{
    return lv_img_get_zoom((lv_obj_t*)a->user_data);
}

void _ui_anim_callback_set_image_angle(lv_anim_t* a, int32_t v)
{
    lv_img_set_angle((lv_obj_t*)a->user_data, v);
}

int32_t _ui_anim_callback_get_image_angle(lv_anim_t* a)
{
    return lv_img_get_angle((lv_obj_t*)a->user_data);
}

void _ui_anim_callback_set_opacity(lv_anim_t *a, int32_t v)
{
    lv_obj_set_style_opa((lv_obj_t *)a->user_data, v, 0);
}

int32_t _ui_anim_callback_get_opacity(lv_anim_t *a)
{
    return lv_obj_get_style_opa((lv_obj_t *)a->user_data, 0);
}

void _ui_anim_callback_set_x(lv_anim_t *a, int32_t v)
{
    lv_obj_set_x((lv_obj_t *)a->user_data, v);
}

int32_t _ui_anim_callback_get_x(lv_anim_t *a)
{
    return lv_obj_get_x_aligned((lv_obj_t *)a->user_data);
}

void _ui_anim_callback_set_y(lv_anim_t *a, int32_t v)
{
    lv_obj_set_y((lv_obj_t *)a->user_data, v);
}

int32_t _ui_anim_callback_get_y(lv_anim_t *a)
{
    return lv_obj_get_y_aligned((lv_obj_t *)a->user_data);
}

void _ui_anim_callback_set_width(lv_anim_t *a, int32_t v)
{
    lv_obj_set_width((lv_obj_t *)a->user_data, v);
}

int32_t _ui_anim_callback_get_width(lv_anim_t *a)
{
    return lv_obj_get_width((lv_obj_t *)a->user_data);
}

void _ui_anim_callback_set_height(lv_anim_t *a, int32_t v)
{
    lv_obj_set_height((lv_obj_t *)a->user_data, v);
}

int32_t _ui_anim_callback_get_height(lv_anim_t *a)
{
    return lv_obj_get_height((lv_obj_t *)a->user_data);
}

void _ui_state_modify(lv_obj_t *target, int32_t state, int value)
{
    if (value == _UI_MODIFY_STATE_TOGGLE)
    {
        if (lv_obj_has_state(target, state))
            lv_obj_clear_state(target, state);
        else
            lv_obj_add_state(target, state);
    }
    else if (value == _UI_MODIFY_STATE_ADD)
        lv_obj_add_state(target, state);
    else
        lv_obj_clear_state(target, state);
}

void _ui_flag_modify(lv_obj_t *target, int32_t flag, int value)
{
    if (value == _UI_MODIFY_FLAG_TOGGLE)
    {
        if (lv_obj_has_flag(target, flag))
            lv_obj_clear_flag(target, flag);
        else
            lv_obj_add_flag(target, flag);
    }
    else if (value == _UI_MODIFY_FLAG_ADD)
        lv_obj_add_flag(target, flag);
    else
        lv_obj_clear_flag(target, flag);
}

void _ui_slider_set_property(lv_obj_t *target, int id, int val)
{
    if (id == _UI_SLIDER_PROPERTY_VALUE_WITH_ANIM)
        lv_slider_set_value(target, val, LV_ANIM_ON);
    if (id == _UI_SLIDER_PROPERTY_VALUE)
        lv_slider_set_value(target, val, LV_ANIM_OFF);
}

void _ui_slider_set_text_value(lv_obj_t *trg, lv_obj_t *src, char *prefix, char *postfix)
{
    char buf[_UI_TEMPORARY_STRING_BUFFER_SIZE];
    lv_snprintf(buf, sizeof(buf), "%s%d%s", prefix, (int)lv_slider_get_value(src), postfix);
    lv_label_set_text(trg, buf);
}

void _ui_label_set_text_value(lv_obj_t *trg, int value)
{
    char buf[_UI_TEMPORARY_STRING_BUFFER_SIZE];
    lv_snprintf(buf, sizeof(buf), "%d", value);
    lv_label_set_text(trg, buf);
}
