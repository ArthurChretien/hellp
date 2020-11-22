/*
** EPITECH PROJECT, 2020
** get_ymax
** File description:
** 
*/
#include <stdlib.h>
#include "proto.h"

int get_ymax(char *dest)
{
    int n = 0;
    char *temp;

    while (dest[n] != '\n') {
        n++;
    }
    temp = malloc(sizeof(char) * n);
    n = 0;
    while (dest[n] != '\n') {
        temp[n] = dest[n];
        n++;
    }
    temp[n] = '\0';
    return (my_getnbr(temp));
}
