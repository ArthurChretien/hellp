/*
** EPITECH PROJECT, 2020
** arg_check.c
** File description:
** 
*/
#include "proto.h"

int arg_check (int ac, char **av)
{
    int arg = my_get_nbr(av[1]);

    if (ac != 2) {
        my_putstr("./my_screensaver: bad arguments:");
        my_putstr(" 0 given but 1 is required\n");
        my_putstr("retry with -h\n");
        return (84);
    }
    if (my_strcmp(av[1], "-h") == 0) {
        my_usage_h();
        return (0);
    }
    if (my_strcmp(av[1], "-d") == 0) {
        my_usage_d();
        return (0);
    }
    if (arg >= 1 && arg <= 3)
        return (arg);
}
