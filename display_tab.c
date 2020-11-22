/*
** EPITECH PROJECT, 2020
** display_tab
** File description:
** 
*/

#include "proto.h"

void display_tab(struct s_list data)
{
    int x = 0;
    int y = 0;

    while (y != data.y_max) {
        x = 0;
        while (x != data.x_max) {
            if (data.tab[y][x] > 0)
                my_putchar('.');
            else if (data.tab[y][x] < 0)
                my_putchar('x');
            else
                my_putchar('o');
            x++;
        }
        my_putchar('\n');
        y++;
    }
}
