#ifndef PM_H
#define PM_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "SLgenerated.h"
#include "pm_obj_anima.h"
#include "../demo/Page.h"
//#include "YH-BSP.h"

/* 關閉背光時，打開背光。雙擊的時間間格(單位: 毫秒) */
#define LV_PM_DOUBLE_CLICK_TIME_INTERVAL 800

/* LV_PM_ORIGIN default value */
#define LV_PM_ORIGIN_PANEL_WIDTH    lv_disp_get_hor_res(NULL)
#define LV_PM_ORIGIN_PANEL_HEIGHT   lv_disp_get_ver_res(NULL)

/* 統一PM背景 */
#define LV_PM_UNITE_STYLE 0
    #if (LV_PM_UNITE_STYLE == 1)
        #define LV_PM_UNITE_STYLE_COLOR 0x000000
    #endif

/* 設定PM頁面的最大數量 */
#ifndef LV_PM_PAGE_NUM
    #define LV_PM_PAGE_NUM 10
#endif

    typedef void (*lv_pm_lifecycle)(lv_obj_t* page);

    /**
     * @brief 轉場動畫
    */
    enum LV_PM_PAGE_ANIMA {
        LV_PM_ANIMA_NONE = 0,       /* 不使用過渡動畫 */
        LV_PM_ANIMA_SLIDE_LEFT,     /* 滑動動畫，新頁面從左往右進場，舊頁面從左離場 */
        LV_PM_ANIMA_SLIDE_RIGHT,    /* 滑動動畫，新頁面從左往右進場，舊頁面從左離場 */
        LV_PM_ANIMA_BUBBLE,         /* 圓形縮放動畫 */
        LV_PM_ANIMA_FADE            /* 淡入淡出動畫，慎用很吃性能 */
    };

    /**
     * @brief 動畫方向
    */
    enum LV_PM_ANIMA_DIR {
        LV_PM_ANIMA_TOP = 0,
        LV_PM_ANIMA_RIGHT = 1,
        LV_PM_ANIMA_BOTTOM = 2,
        LV_PM_ANIMA_LEFT = 3
    };

    /**
    * @brief PM狀態
    */
    enum LV_PM_STATE {
        LV_PM_STATE_OK = 0, /* OK */
        LV_PM_STATE_ERROR = 1, /* ERROR */
        LV_PM_STATE_TIMEOUT = 2, /* TIMEOUT */
        LV_PM_STATE_NOPAGE = 3, /* NO PAGE */
        LV_PM_STATE_PAGEFULL = 4 /* PAGE Full */
    };

    /**
     * @brief 頁面管理策略
    */
    enum LV_PM_OPEN_TARGET {
        LV_PM_TARGET_NEW = 0,                /* 開啟一個新的頁面 */
        LV_PM_TARGET_SELF = 1,               /* 在目前頁面開啟（先關閉目前的頁面，再開啟新頁面） */
        // LV_PM_TARGET_RESET = 2         /*  只開啟目前頁面（先關閉所有頁面，再打開新頁面） */
    };

    /**
     * @brief 設定動畫的結體
    */
    typedef struct _lv_pm_open_options_t
    {
        enum LV_PM_PAGE_ANIMA animation;
        enum LV_PM_OPEN_TARGET target;
        //enum LV_PM_ANIMA_DIR direction;       /*暫無功能*/
    } lv_pm_open_options_t;

    /**
    * @brief 頁面的生命週期
    */
    typedef struct _lv_pm_page_t
    {
        lv_obj_t* page;                                           /* 頁面 */
        lv_pm_lifecycle onLoad;                          /* 頁面創建，可以在這裡執行初始化 */
        lv_pm_lifecycle willAppear;                    /* 頁面即將進場 */
        lv_pm_lifecycle didAppear;                     /* 頁面進場完成 ，如果有動畫可以在這裡執行 lv_anim_start，將會自動播放  */
        lv_pm_lifecycle willDisappear;              /* 頁面即將離場 */
        lv_pm_lifecycle didDisappear;              /* 頁面離場完成 */
        lv_pm_lifecycle unLoad;                          /* 頁面被關閉，你需要在這裡釋放所有臨時記憶體，否則可能記憶體洩漏 */
        lv_pm_open_options_t _options;         /* 動畫設定 */
    } lv_pm_page_t;

    /*****************************************************************************************/

    extern lv_pm_open_options_t options;
    extern lv_obj_t* lv_pm_origin_dot;
    extern lv_obj_t* lv_pm_origin_panel;



    uint8_t lv_pm_init(void);
    lv_pm_page_t* lv_pm_create_page(uint8_t id);
    uint8_t lv_pm_open_page(uint8_t id, lv_pm_open_options_t* behavior);
    void lv_pm_enter_sleepmode(void);
    void lv_pm_exit_sleepmode(void);
    void lv_pm_origin_create(void);
    void lv_pm_origin_reset(void);



#ifdef __cplusplus
} /*extern "C"*/
#endif
#endif
