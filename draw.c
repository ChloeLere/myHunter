/*
** EPITECH PROJECT, 2021
** drax
** File description:
** draw_obj
*/

#include "lib/my/my.h"

void draw_obj(game_object_t obj, sfRenderWindow *window)
{
    sfSprite_setPosition(obj->sprite, obj->position);
    sfSprite_setTextureRect(obj->sprite, obj->box);
    sfRenderWindow_drawSprite(window, obj->sprite, NULL);
}

void draw_game(all_element_t obj, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, obj->backgroud->sprite, NULL);
    draw_obj(obj->bird1, window);
    draw_obj(obj->bird2, window);
    draw_obj(obj->life, window);
    sfRenderWindow_drawText(window, obj->score->text, NULL);
    draw_obj(obj->p_object, window);
}

void draw_main_paused(sfRenderWindow *window, screen_t obj)
{
    sfRenderWindow_drawSprite(window, obj->sprite, NULL);
}

void draw_win_lose(all_element_t obj, screen_t sc, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, sc->sprite, NULL);
    sfRenderWindow_drawText(window, obj->score->text, NULL);
    sfRenderWindow_drawText(window, obj->high_sc->text, NULL);
}
