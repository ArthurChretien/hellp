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
    fb->pixels[y * fb->width + x] = c.r;
    fb->pixels[y * fb->width + x + 1] = c.r;
    fb->pixels[y * fb->width + x + 2] = c.r;
    fb->pixels[y * fb->width + x + 3] = c.r;
    return (0);
}

void my_draw_lineX(framebuffer_t *fb, sfVector2i from,
sfVector2i to, sfColor sfRed)
{
    double a;

    a = (to.y - from.y) / (to.x - from.x);
    from.y = a * from.x + (from.x - (a * from.y));
    while (from.x < to.x) {
        my_put_pixel(fb, from.x, from.y, sfRed);
        from.y += a;
        from.x++;
    }
}

void my_draw_lineY(framebuffer_t *fb, sfVector2i from,
sfVector2i to, sfColor sfRed)
{
    double a;

    a = (to.x - from.x) / (to.y - from.y);
    from.y = a * from.y + (from.y - (a * from.x));
    while (from.y < to.y) {
        my_put_pixel(fb, from.x, from.y, sfRed);
        from.x += a;
        from.y++;
    }
}

void draw_line(framebuffer_t *buffer, sfVector2i a,
sfVector2i b, sfColor colors)
{
    if (abs(b.x - a.x) >= abs(b.y - a.y))
        if (b.x >= a.x)
            my_draw_lineX(buffer, a, b, sfRed);
        else
            my_draw_lineY(buffer, b , a, sfRed);
    else
        if (b.y >= a.y)
            my_draw_lineY(buffer, a, b, sfRed);
        else
            my_draw_lineY(buffer, b, a, sfRed);
}