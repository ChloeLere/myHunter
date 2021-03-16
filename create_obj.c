/*
** EPITECH PROJECT, 2021
** create_obj
** File description:
** help for create all obj
*/

#include "lib/my/my.h"

sfRenderWindow *create_window(unsigned int x, unsigned int y,
unsigned int bpp, char *title)
{
    sfVideoMode video_mode = {x, y, bpp};
    sfRenderWindow *cw;

    cw = sfRenderWindow_create(video_mode, title, sfClose | sfResize, NULL);
    return (cw);
}

screen_t create_screen(char *name)
{
    screen_t s = malloc(sizeof(*s));

    s->sprite = sfSprite_create();
    s->texture = sfTexture_createFromFile(name, NULL);
    return (s);
}

game_object_t create_object(const char *name_sprite,
sfVector2f pos, sfIntRect rect, sfVector2f sc)
{
    game_object_t obj = malloc(sizeof(*obj));

    obj->sprite = sfSprite_create();
    obj->texture = sfTexture_createFromFile(name_sprite, NULL);
    obj->position = pos;
    obj->box = rect;
    obj->scale = sc;
    return (obj);
}

text_t create_text(char *namefont, int x, int y)
{
    text_t text = malloc(sizeof(*text));

    text->font = sfFont_createFromFile(namefont);
    text->text = sfText_create();
    text->position.x = x;
    text->position.y = y;
    return (text);
}