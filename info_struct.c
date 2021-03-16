/*
** EPITECH PROJECT, 2021
** info_struct
** File description:
** init info struct
*/

#include "lib/my/my.h"

info_t create_info_struct(void)
{
    info_t data;

    data.bb1.height = 200;
    data.bb1.left = 0;
    data.bb1.top = 0;
    data.bb1.width = 200;
    data.pb1.x = 0;
    data.pb1.y = 0;
    data.sb1.x = 1;
    data.sb1.y = 1;
    return (data);
}