/*
** EPITECH PROJECT, 2021
** create_all_object
** File description:
** init struct
*/

#include "lib/my/my.h"

all_element_t create_all_obj(void)
{
    all_element_t obj = malloc(sizeof(*obj));

    obj->status = 1;
    obj->point = 0;
    obj->hdl_life = 3;
    obj->left_right = 0;
    obj->right = 0;
    obj->left = 0;
    obj->maj = 0;
    obj->temp = 0;
    obj->clock_b1 = sfClock_create();
    obj->clock_b2 = sfClock_create();
    obj = create_all_game_obj(obj);
    obj = create_all_screens(obj);
    obj = create_all_texts(obj);
    return (obj);
}

all_element_t create_all_game_obj(all_element_t obj)
{
    sfVector2f pb1 = {-50.0, rand() % 550};
    sfVector2f sb = {0.5, 0.5};
    sfVector2f pb2 = {850.0, rand() % 550};
    sfIntRect bb = {65, 40, 155, 150};
    sfVector2f pbl = {600.0, 530};
    sfVector2f sl = {1, 1};
    sfIntRect bl = {0, 0, 150, 40};
    sfVector2f pbp = {720, 15};
    sfIntRect bp = {135, 135, 90, 90};
    sfVector2f sp = {0.70, 0.70};

    obj->bird1 = create_object("src/pioupiou.png", pb1, bb, sb);
    obj->bird2 = create_object("src/piou.png", pb2, bb, sb);
    obj->life = create_object("src/life.png", pbl, bl, sl);
    obj->p_object = create_object("src/pause.png", pbp, bp, sp);
    return (obj);
}

all_element_t create_all_screens(all_element_t obj)
{
    obj->backgroud = create_screen("src/background.jpg");
    obj->main_menu = create_screen("src/main_menu.jpg");
    obj->paused = create_screen("src/paused.jpg");
    obj->lose = create_screen("src/game_over.jpg");
    obj->win = create_screen("src/victory.jpg");
    return (obj);
}

all_element_t create_all_texts(all_element_t obj)
{
    obj->score = create_text("src/arial.ttf", 0, 0);
    obj->high_sc = create_text("src/arial.ttf", 560, 525);
    return (obj);
}
