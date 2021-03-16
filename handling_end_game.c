
/*
** EPITECH PROJECT, 2021
** handling_end_game
** File description:
** win or lose
*/

#include "lib/my/my.h"

void handling_end_game(all_element_t obj)
{
    if (obj->hdl_life <= 0)
        obj->status = 4;
    if (obj->point >= 10000)
        obj->status = 3;
}

void put_game_to_zero(all_element_t obj)
{
    obj->point = 0;
    obj->hdl_life = 3;
    obj->bird1->position.x = -50;
    obj->bird2->position.x = 850;
    obj->bird1->position.y = rand() % 550;
    obj->left = 0;
    obj->bird2->position.y = rand() % 550;
    obj->right = 0;
    obj->life->box.top = 0;
    obj->temp = 0;
    obj->maj = 0;
}