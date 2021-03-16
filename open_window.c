/*
** EPITECH PROJECT, 2021
** open_window
** File description:
** handling window_open
*/

#include "lib/my/my.h"

void analyse_event(sfRenderWindow *window, sfEvent event, all_element_t obj)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtKeyPressed) {
        if (sfKeyboard_isKeyPressed(sfKeyEscape) && obj->status != 5)
            obj->status = 5;
    }
}

void status_game(all_element_t obj, sfEvent event, sfRenderWindow *window)
{
    if (obj->status == 1)
        main_menu(obj, event, window);
    if (obj->status == 2)
        play_game(obj, event, window);
    if (obj->status == 3)
        win_menu(obj, event, window);
    if (obj->status == 4)
        lose_menu(obj, event, window);
    if (obj->status == 5)
        paused_menu(obj, event, window);
}

void open_window(void)
{
    sfEvent event;
    all_element_t obj = create_all_obj();
    sfRenderWindow *window = create_window(800, 600, 32, "Hunter");

    set_all_obj(obj, window);
    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)) {
        status_game(obj, event, window);
        display_window(window);
    }
    destroy_all(obj, window);
}
