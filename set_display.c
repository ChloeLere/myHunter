/*
** EPITECH PROJECT, 2021
** set_display
** File description:
** set & display
*/

#include "lib/my/my.h"

void set_game_obj(game_object_t obj, sfRenderWindow *window)
{
    sfSprite_setScale(obj->sprite, obj->scale);
    sfSprite_setTextureRect(obj->sprite, obj->box);
    sfSprite_setTexture(obj->sprite, obj->texture, sfFalse);
}

void set_all_obj(all_element_t obj, sfRenderWindow *window)
{
    set_game_obj(obj->bird1, window);
    set_game_obj(obj->bird2, window);
    set_game_obj(obj->p_object, window);
    set_game_obj(obj->life, window);
    set_text("0", obj->score, 45);
    set_text("0", obj->high_sc, 25);
    sfSprite_setTexture(obj->backgroud->sprite,
    obj->backgroud->texture, sfFalse);
    sfSprite_setTexture(obj->main_menu->sprite,
    obj->main_menu->texture, sfFalse);
    sfSprite_setTexture(obj->paused->sprite, obj->paused->texture, sfFalse);
    sfSprite_setTexture(obj->lose->sprite, obj->lose->texture, sfFalse);
    sfSprite_setTexture(obj->win->sprite, obj->win->texture, sfFalse);
}

void display_window(sfRenderWindow *window)
{
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfBlack);
}

void set_text(char *ptn, text_t txt, int size)
{
    sfText_setString(txt->text, ptn);
    sfText_setFont(txt->text, txt->font);
    sfText_setCharacterSize(txt->text, size);
}