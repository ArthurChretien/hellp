/*
** EPITECH PROJECT, 2021
** arg_check
** File description:
** arg_check
*/

#include "proto.h"

int arg_check (char **av)
{
    if (my_strcmp(av[1], "-h") == 0) {
        usage();
        return (0);
    }
    if (my_strcmp(av[1], "-i") == 0) {
        usage_i();
        return (0);
    }
    return (1);
}