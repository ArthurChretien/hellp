/*
** EPITECH PROJECT, 2020
** get_tab
** File description:
** 
*/
#include <stdlib.h>
#include "proto.h"

int **get_tab(struct s_list data, char *dest)
{
    int y = 0;
    int x = 0;
    int n = 0;

    data.tab = malloc(sizeof(int *) * (data.y_max + 1));
    data.tab[y] = malloc(sizeof(int) * (data.x_max + 1));
    while (dest[n] != '\n' && dest[n] != '\0')
        n++;
    n++;
    for (; dest[n] != '\0'; n++) {
        if (dest[n] == '\n') {
            y++;
            x = 0;
            data.tab[y] = malloc(sizeof(int) * (data.x_max + 1));
        }
        else if (dest[n] == '.')
            data.tab[y][x++] = 1;
        else
            data.tab[y][x++] = 0;
    }
    return (data.tab);
}
