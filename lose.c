/*
** EPITECH PROJECT, 2021
** lose
** File description:
** when the player lose
*/

#include "lib/my/my.h"

void lose_menu(all_element_t obj, sfEvent event, sfRenderWindow *window)
{
    if (obj->temp == 0)
        display_score_end(obj, window);
    while (sfRenderWindow_pollEvent(window, &event)) {
        analyse_event(window, event, obj);
        a_e_win_lose(obj, event, window);
    }
    draw_win_lose(obj, obj->lose, window);
}