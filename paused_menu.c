/*
** EPITECH PROJECT, 2021
** paused_menu
** File description:
** hdlg paused
*/

#include "lib/my/my.h"

void analyse_event_paused(all_element_t obj, sfEvent event,
sfRenderWindow *window)
{
    if (event.type == sfEvtMouseButtonPressed) {
        if (event.mouseButton.y > 203 && event.mouseButton.y < 250
        && event.mouseButton.x > 271 && event.mouseButton.x < 533)
            obj->status = 2;
        if (event.mouseButton.y > 340 && event.mouseButton.y < 388
        && event.mouseButton.x > 265 && event.mouseButton.x < 545) {
            obj->status = 2;
            put_game_to_zero(obj);
        }
        if (event.mouseButton.y > 470 && event.mouseButton.y < 520
        && event.mouseButton.x > 331 && event.mouseButton.x < 474)
            sfRenderWindow_close(window);
    }
    if (event.type == sfEvtKeyPressed) {
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            obj->status = 2;
    }
}

void paused_menu(all_element_t obj, sfEvent event, sfRenderWindow *window)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        analyse_event(window, event, obj);
        analyse_event_paused(obj, event, window);
    }
    draw_main_paused(window, obj->paused);
}