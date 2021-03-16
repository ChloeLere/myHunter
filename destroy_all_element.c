/*
** EPITECH PROJECT, 2021
** destroy_all_element
** File description:
** destroy
*/

#include "lib/my/my.h"

void destroy_all(all_element_t obj, sfRenderWindow *window)
{
    destroy_game_obj(obj->bird1);
    destroy_game_obj(obj->bird2);
    destroy_game_obj(obj->p_object);
    destroy_game_obj(obj->life);
    destroy_screen_obj(obj->backgroud);
    destroy_screen_obj(obj->main_menu);
    destroy_screen_obj(obj->paused);
    destroy_screen_obj(obj->lose);
    destroy_screen_obj(obj->win);
    destroy_text_obj(obj->high_sc);
    destroy_text_obj(obj->score);
    sfClock_destroy(obj->clock_b1);
    sfClock_destroy(obj->clock_b2);
    sfRenderWindow_destroy(window);
}

void destroy_game_obj(game_object_t obj)
{
    sfSprite_destroy(obj->sprite);
    sfTexture_destroy(obj->texture);
}

void destroy_screen_obj(screen_t obj)
{
    sfSprite_destroy(obj->sprite);
    sfTexture_destroy(obj->texture);
}

void destroy_text_obj(text_t obj)
{
    sfText_destroy(obj->text);
    sfFont_destroy(obj->font);
}