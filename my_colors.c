/*
** EPITECH PROJECT, 2020
** my_colors.c
** File description:
** 
*/
#include "proto.h"

sfColor my_colors(sfUint8 r, sfUint8 g, sfUint8 b, sfUint8 a)
{
    sfColor color;

    color.r = r;
    color.g = g;
    color.b = b;
    color.a = a;

    return (color);
}
