/*
** EPITECH PROJECT, 2020
** check_arg
** File description:
** 
*/
#include "proto.h"

int check_arg(int ac, char **av)
{
    int i = 1;

    while (i < ac - 1) {
        if (my_getnbr(av[i]) <= (my_getnbr(av[i + 1])))
            i++;
        else
            return (1);
    }
    return (0);
}
