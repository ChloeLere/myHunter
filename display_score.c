/*
** EPITECH PROJECT, 2021
** display_score
** File description:
** display score
*/

#include "lib/my/my.h"

void display_score_game(all_element_t obj, sfRenderWindow *window)
{
    char *sc = NULL;

    sc = int_to_char(obj->point);
    sfText_setString(obj->score->text, sc);
    sfText_setFont(obj->score->text, obj->score->font);
    sfText_setCharacterSize(obj->score->text, 45);
    sfText_setPosition(obj->score->text, obj->score->position);
    free(sc);
    obj->maj = 1;
}

void display_score_end(all_element_t obj, sfRenderWindow *window)
{
    sfVector2f pos_score = {90, 115};
    sfVector2f best_score_pos = {145, 143};
    char *first_score = int_to_char(obj->point);
    char *best_score = find_the_bigger(obj->point, first_score);

    sfText_setString(obj->score->text, first_score);
    sfText_setFont(obj->score->text, obj->score->font);
    sfText_setCharacterSize(obj->score->text, 25);
    sfText_setPosition(obj->score->text, pos_score);
    sfText_setString(obj->high_sc->text, best_score);
    sfText_setFont(obj->high_sc->text, obj->high_sc->font);
    sfText_setCharacterSize(obj->high_sc->text, 25);
    sfText_setPosition(obj->high_sc->text, best_score_pos);
    free(first_score);
    obj->temp = 1;
}