#ifndef PAGE_H
#define PAGE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#include "sys.h"
#define Print rt_kprintf
#else
#include "../lvgl/lvgl.h"
#endif

#include "stdlib.h"
#include "stdio.h"
#include "lvgl-pm/pm.h"

/* PageStartup */
void InitPageStartup(lv_obj_t* page);
void DeInitPageStartup(lv_obj_t* page);

/* Pages1 */
void InitPages1(lv_obj_t* page);
void didAppearPages1(lv_obj_t* page);
void DeInitPages1(lv_obj_t* page);

/* Pages2 */
void InitPages2(lv_obj_t* page);
void DeInitPages2(lv_obj_t* page);

/* Pages3 */
void InitPages3(lv_obj_t* page);
void DeInitPages3(lv_obj_t* page);

 /* 字型宣告 */
LV_FONT_DECLARE(lv_font_montserratMedium_24);
LV_FONT_DECLARE(lv_font_montserrat_36);
LV_FONT_DECLARE(NotoSansTC_Regular_16);

/* 圖片宣告 */
LV_IMG_DECLARE(img_cogwheel_argb);
LV_IMG_DECLARE(ui_img_page1_bg_png);    
LV_IMG_DECLARE(ui_img_page1_arc_png);
LV_IMG_DECLARE(ui_img_page1_menu_png);
LV_IMG_DECLARE(ui_img_water_001_png);
LV_IMG_DECLARE(ui_img_a1_png);
LV_IMG_DECLARE(ui_img_a2_png);
LV_IMG_DECLARE(ui_img_a3_png);
LV_IMG_DECLARE(ui_img_powertip001_png);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
