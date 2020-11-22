/*
** EPITECH PROJECT, 2020
** replace_by_neg_bis
** File description:
** 
*/
#include "proto.h"

int **replace_by_neg_bis(struct s_list data, int res, int x, int y)
{
    int j = y - (res - 1);
    int i = x - (res - 1);

    for (; j <= y; j++) {
        i = x - (res - 1);
        for (; i <= x; i++) {
            data.tab[j][i] = -1;
        }
    }
    return (data.tab);
}
