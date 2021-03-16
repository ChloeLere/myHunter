/*
** EPITECH PROJECT, 2021
** random
** File description:
** random spawn
*/

#include "lib/my/my.h"

void random_spawn(all_element_t obj)
{
    if (obj->left == 0)
        obj->left = rand() % 150;
    if (obj->right == 0)
        obj->right = rand() % 150;
    if (obj->left > 120)
        left(obj);
    else
        obj->left = 0;
    if (obj->right > 120)
        right(obj);
    else
        obj->right = 0;
}

void left(all_element_t obj)
{
    if (sfTime_asMicroseconds(sfClock_getElapsedTime(obj->clock_b1))
    >= 119000) {
        obj->bird1->box.top += 136;
        obj->bird1->position.x += 15;
        if (obj->bird1->box.left > 400 && obj->bird1->box.top >= 448)
            obj->bird1->box.left = 65;
        if (obj->bird1->box.top >= 448) {
            obj->bird1->box.top = 40;
            obj->bird1->box.left += 170;
        }
        sfClock_restart(obj->clock_b1);
    }
    end_left(obj);
}

void right(all_element_t obj)
{
    if (sfTime_asMicroseconds(sfClock_getElapsedTime(obj->clock_b2))
    >= 105900) {
        obj->bird2->box.top += 136;
        obj->bird2->position.x -= 15;
        if (obj->bird2->box.top >= 448 && obj->bird2->box.left >= 400)
            obj->bird2->box.left = 65;
        if (obj->bird2->box.top >= 448) {
            obj->bird2->box.top = 40;
            obj->bird2->box.left += 170;
        }
        sfClock_restart(obj->clock_b2);
    }
    end_right(obj);
}