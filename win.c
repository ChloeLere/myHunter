/*
** EPITECH PROJECT, 2021
** win
** File description:
** when the player win
*/

#include "lib/my/my.h"

void a_e_win_lose(all_element_t obj, sfEvent event, sfRenderWindow *window)
{
    if (event.type == sfEvtMouseButtonPressed) {
        if (event.mouseButton.y > 200 && event.mouseButton.y < 250
        && event.mouseButton.x > 260 && event.mouseButton.x < 545) {
            obj->status = 2;
            put_game_to_zero(obj);
        }
        if (event.mouseButton.y > 336 && event.mouseButton.y < 387
        && event.mouseButton.x > 332 && event.mouseButton.x < 470)
            sfRenderWindow_close(window);
    }
}

void win_menu(all_element_t obj, sfEvent event, sfRenderWindow *window)
{
    if (obj->temp == 0)
        display_score_end(obj, window);
    while (sfRenderWindow_pollEvent(window, &event)) {
        analyse_event(window, event, obj);
        a_e_win_lose(obj, event, window);
    }
    draw_win_lose(obj, obj->win, window);
}