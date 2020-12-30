/*
** EPITECH PROJECT, 2020
** framebuffer_create
** File description:
** framebuffer_create
*/
#include "proto.h"

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    my_putchar('A');
    framebuffer_t *buffer = malloc(sizeof(framebuffer_t *));
    my_putchar('B');

    buffer->width = width;
    buffer->height = height;
    buffer->pixels = malloc(width * height * 4);
    my_putchar('C');
    return (buffer);
}

void framebuffer_destroy(framebuffer_t *framebuffer)
{
    free(framebuffer->pixels);
    free(framebuffer);
}
