/*
** EPITECH PROJECT, 2020
** push_swap
** File description:
** 
*/
#include "proto.h"
#include <stdlib.h>
#include <stddef.h>

int main(int ac, char **av)
{
    list *l_a = NULL;
    list *l_b = NULL;
    int i = 1;

    if (ac <= 2)
        return (84);
    if (check_arg(ac, av) == 0)
        return (0);
    if (check_arg(ac, av) == 1) {
        while (i < ac) {
            l_a = add_at_position(l_a, my_getnbr(av[i]), (i - 1));
            i++;
        }
        swap_l_a(l_a);
        print_list(l_a);
        l_a = free_list(l_a);
        l_b = free_list(l_b);
    }
    return (0);
}
