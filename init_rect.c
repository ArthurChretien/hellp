/*
** EPITECH PROJECT, 2021
** init_rect
** File description:
** init_rect
*/
#include "proto.h"

sfIntRect init_rect(void)
{
    sfIntRect rect;

    rect.top = 0;
    rect.left = 0;
    rect.width = 50;
    rect.height = 70;

    return (rect);
}