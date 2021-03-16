/*
** EPITECH PROJECT, 2021
** game
** File description:
** hdlg game
*/

#include "lib/my/my.h"

void analyse_event_game(all_element_t obj, sfEvent event,
sfRenderWindow *window)
{
    if (event.type == sfEvtMouseButtonPressed) {
        if ((event.mouseButton.y >= obj->bird1->position.y
        && event.mouseButton.y <= obj->bird1->position.y + 60)
        && (event.mouseButton.x <= obj->bird1->position.x + 60
        && event.mouseButton.x >= obj->bird1->position.x)) {
            touch_b1(obj);
            return;
        }
        if ((event.mouseButton.y >= obj->bird2->position.y
        && event.mouseButton.y <= obj->bird2->position.y + 60)
        && (event.mouseButton.x <= obj->bird2->position.x + 60
        && event.mouseButton.x >= obj->bird2->position.x)) {
            touch_b2(obj);
            return;
        }
        obj->hdl_life -= 1;
        handling_life(obj);
    }
}

int analyse_event_bp(all_element_t obj, sfEvent event, sfRenderWindow *window)
{
    if (event.type == sfEvtMouseButtonPressed) {
        if (event.mouseButton.y > 15 && event.mouseButton.y < 75
        && event.mouseButton.x > 715 && event.mouseButton.x < 790) {
            obj->status = 5;
            return (-1);
        }
    }
    return (0);
}

void play_game(all_element_t obj, sfEvent event, sfRenderWindow *window)
{
    handling_end_game(obj);
    random_spawn(obj);
    if (obj->maj == 0)
        display_score_game(obj, window);
    while (sfRenderWindow_pollEvent(window, &event)) {
        analyse_event(window, event, obj);
        if (analyse_event_bp(obj, event, window) == -1)
            break;
        analyse_event_game(obj, event, window);
    }
    draw_game(obj, window);
}

void handling_life(all_element_t obj)
{
    if (obj->life->box.top >= 120)
        obj->life->box.top = 0;
    obj->life->box.top += 42;
}