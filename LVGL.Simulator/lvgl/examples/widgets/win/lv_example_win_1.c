﻿#include "../../lv_examples.h"
#if LV_USE_WIN && LV_BUILD_EXAMPLES


static void event_handler(lv_event_t* e)
{
    lv_obj_t* obj = lv_event_get_target(e);
    LV_LOG_USER("Button %d clicked", (int)lv_obj_get_index(obj));
}

void lv_win_close_event_cb(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t* obj = lv_event_get_target(e);
    LV_LOG_USER("Button %d clicked", (int)lv_obj_get_index(obj));
    switch (code)
    {
    case LV_EVENT_CLICKED:
    {
        lv_obj_t* win = (lv_obj_t*)e->user_data;
        printf("LV_EVENT_CLICKED\r\n");
        lv_obj_del(win);
        
    }
    break;
    default:
        break;
    }
}

void lv_example_win_1(void)
{
    lv_obj_t* win = lv_win_create(lv_scr_act(), 40);
    lv_obj_t* btn;
    btn = lv_win_add_btn(win, LV_SYMBOL_LEFT, 40);
    lv_obj_add_event_cb(btn, event_handler, LV_EVENT_CLICKED, NULL);

    lv_win_add_title(win, "A title");

    btn = lv_win_add_btn(win, LV_SYMBOL_RIGHT, 40);
    lv_obj_add_event_cb(btn, event_handler, LV_EVENT_CLICKED, NULL);

    btn = lv_win_add_btn(win, LV_SYMBOL_CLOSE, 60);
    lv_obj_add_event_cb(btn, lv_win_close_event_cb, LV_EVENT_CLICKED, win);

    lv_obj_t* cont = lv_win_get_content(win);  /*Content can be added here*/
    lv_obj_t* label = lv_label_create(cont);
    lv_label_set_text(label, "This is\n"
        "a pretty\n"
        "long text\n"
        "to see how\n"
        "the window\n"
        "becomes\n"
        "scrollable.\n"
        "\n"
        "\n"
        "Some more\n"
        "text to be\n"
        "sure it\n"
        "overflows. :)");


}

#endif
