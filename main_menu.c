/*
** EPITECH PROJECT, 2021
** main_menu
** File description:
** handling main menu
*/

#include "lib/my/my.h"

void analyse_event_start(all_element_t obj, sfEvent event,
sfRenderWindow *window)
{
    analyse_event(window, event, obj);
    if (event.type == sfEvtMouseButtonPressed) {
        if (event.mouseButton.y > 205 && event.mouseButton.y < 250
        && event.mouseButton.x > 320 && event.mouseButton.x < 480)
            obj->status = 2;
        if (event.mouseButton.y > 340 && event.mouseButton.y < 383
        && event.mouseButton.x > 331 && event.mouseButton.x < 474)
            sfRenderWindow_close(window);
    }
}

void main_menu(all_element_t obj, sfEvent event, sfRenderWindow *window)
{
    while (sfRenderWindow_pollEvent(window, &event))
        analyse_event_start(obj, event, window);
    draw_main_paused(window, obj->main_menu);
}