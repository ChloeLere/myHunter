/*
** EPITECH PROJECT, 2021
** spawn_enemy
** File description:
** part 2 display enemy
*/

#include "lib/my/my.h"

void end_left(all_element_t obj)
{
    if (obj->bird1->position.x >= 860) {
        obj->bird1->position.y = rand() % 550;
        obj->bird1->position.x = -50;
        obj->hdl_life -= 1;
        obj->left = 0;
        handling_life(obj);
    }
}

void end_right(all_element_t obj)
{
    if (obj->bird2->position.x <= -60) {
        obj->bird2->position.y = rand() % 550;
        obj->bird2->position.x = 850;
        obj->hdl_life -= 1;
        obj->right = 0;
        handling_life(obj);
    }
}