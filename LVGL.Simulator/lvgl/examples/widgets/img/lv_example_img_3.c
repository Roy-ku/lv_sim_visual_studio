#include "../../lv_examples.h"
#include "./SLgenerated.h"
#if LV_USE_IMG && LV_BUILD_EXAMPLES

static void set_angle(void * img, int32_t v)
{
    lv_img_set_angle(img, v);
}

static void set_zoom(void * img, int32_t v)
{
    lv_img_set_zoom(img, v);
}


/**
 * Show transformations (zoom and rotation) using a pivot point.
 */
//void lv_example_img_3(void)
//{
//    LV_IMG_DECLARE(img_cogwheel_argb);
//
//    /*Now create the actual image*/
//    lv_obj_t * img = lv_img_create(lv_scr_act());
//    lv_img_set_src(img, &img_cogwheel_argb);
//    lv_obj_align(img, LV_ALIGN_CENTER, 0, 0);
//    lv_img_set_pivot(img, 50, 50);    /*Rotate around the top left corner*/
//
//    lv_anim_t a;
//    lv_anim_init(&a);
//    lv_anim_set_var(&a, img);
//    lv_anim_set_exec_cb(&a, set_angle);
//    lv_anim_set_values(&a, 0, 3600);
//    lv_anim_set_time(&a, 5000);
//    lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);
//    lv_anim_start(&a);
//
//    lv_anim_set_exec_cb(&a, set_zoom);
//    lv_anim_set_values(&a, 128, 256);
//    lv_anim_set_playback_time(&a, 3000);
//    lv_anim_start(&a);
//}
//void _ui_anim_callback_set_image_angle(lv_anim_t* a, int32_t v)
//{
//    lv_img_set_angle((lv_obj_t*)a->user_data, v);
//}
//int32_t _ui_anim_callback_get_image_angle(lv_anim_t* a)
//{
//    return lv_img_get_angle((lv_obj_t*)a->user_data);
//}
void lv_example_img_3(void)
{
    LV_IMG_DECLARE(img_cogwheel_argb);

    /*Now create the actual image*/
    lv_obj_t* img = lv_img_create(lv_scr_act());
    lv_img_set_src(img, &img_cogwheel_argb);
    lv_obj_align(img, LV_ALIGN_CENTER, 0, 0);
    lv_img_set_pivot(img, 50, 50);    /*Rotate around the top left corner*/

    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 5000);
    lv_anim_set_user_data(&PropertyAnimation_0, img);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_image_angle);
    lv_anim_set_values(&PropertyAnimation_0, 0, 3600);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, 0);
    lv_anim_set_playback_time(&PropertyAnimation_0, 5000);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, LV_ANIM_REPEAT_INFINITE);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_image_angle);
    lv_anim_start(&PropertyAnimation_0);
}

#endif
