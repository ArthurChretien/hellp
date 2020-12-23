/*
** EPITECH PROJECT, 2020
** draw_line
** File description:
** 
*/
#include "proto.h"

int my_put_pixel(framebuffer_t *fb, unsigned int x, unsigned int y, sfColor c)
{
    if (x < 1 || y < 1 || x > 799 || y > 599)
        return (EXIT_FAILURE);
    y = y * 4;
    x = x * 4;
    buffer->pixels[y * buffer->width + x] = c.r;
    buffer->pixels[y * buffer->width + x + 1] = c.r;
    buffer->pixels[y * buffer->width + x + 2] = c.r;
    buffer->pixels[y * buffer->width + x + 3] = c.r;
    return (0);
}

int draw_line(framebuffer_t *buffer, sfVector2i a, sfVector2i b, sfColor colors)
{
    return (0);
}
