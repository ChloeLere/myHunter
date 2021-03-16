/*
** EPITECH PROJECT, 2021
** touch
** File description:
** action when bird is touch
*/

#include "lib/my/my.h"

void touch_b1(all_element_t obj)
{
    obj->point += 1000;
    obj->bird1->position.x = -50;
    obj->bird1->position.y = rand() % 550;
    obj->left = 0;
    obj->maj = 0;
}

void touch_b2(all_element_t obj)
{
    obj->point += 1000;
    obj->bird2->position.x = 850;
    obj->bird2->position.y = rand() % 550;
    obj->right = 0;
    obj->maj = 0;
}