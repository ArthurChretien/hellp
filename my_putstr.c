/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** 
*/
#include <unistd.h>
#include "proto.h"

void my_putstr(char const *str)
{
    int n = 0;

    while (str[n] != '\0') {
        my_putchar(str[n]);
        n++;
    }
}
