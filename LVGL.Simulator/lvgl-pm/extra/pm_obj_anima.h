#ifndef _PM_OBJ_ANIMA_H_
#define _PM_OBJ_ANIMA_H_
#ifdef __cplusplus
extern "C"
{
#endif
	#include "lvgl.h"

	enum ANIM_DIR
	{
		ANIM_DIR_TOP = 0,
		ANIM_DIR_BOTTOM = 1,
		ANIM_DIR_LEFT = 2,
		ANIM_DIR_RIGHT = 3,
	};
	typedef uint8_t lv_pm_obj_anim_dir_t;

	void lv_pm_obj_anima_smooth_in(lv_obj_t * targetobject, lv_pm_obj_anim_dir_t dir, int delay);
    void lv_pm_obj_anima_fade_in(lv_obj_t* targetobject, int delay);
    void lv_pm_obj_anima_fade_out(lv_obj_t* targetobject, int delay);
    void lv_pm_obj_anima_fade_in_out(lv_obj_t* targetobject, int delay, int time, int playback_time, int repeat_delay, int repeat_count);
    void lv_pm_obj_anima_none_in(lv_obj_t* targetobject);
	void lv_pm_obj_anima_none_out(lv_obj_t * targetobject);
	void lv_custom_obj_jump_anim(lv_obj_t * targetobject, int delay);


#ifdef __cplusplus
}
#endif
#endif /* _PM_OBJ_ANIMA_H_ */
