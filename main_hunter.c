/*
** EPITECH PROJECT, 2021
** main_hunter
** File description:
** main hunter
*/

#include "lib/my/my.h"

int display_h(char *str)
{
    if (str[0] == '-' && str[1] == 'h') {
        my_printf("Finite hunter created with CSFML.\n\nUSAGE\n");
        my_printf(" ./my_hunter\n\n");
        my_printf("OPTIONS\n -h\t\tprint the usage and quit.\n\n");
        my_printf("USER INTERACTIONS\n Mouse Button\tkill bird.\n");
        my_printf(" ESCAPE_KEY\tpaused.\n");
        return (0);
    }
    return (-1);
}

int main(int argc, char **argv)
{
    if (argc > 1) {
        if (display_h(argv[1]) == 0)
            return (0);
    }
    open_window();
    return (0);
}
