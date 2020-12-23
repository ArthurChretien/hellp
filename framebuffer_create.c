/*
** EPITECH PROJECT, 2020
** framebuffer_create
** File description:
** framebuffer_create
*/
#include "proto.h"

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t buffer;

    buffer = malloc(sizeof(*buffer));
    buffer.width = width;
    buffer.height = height;
    buffer_len = width * height * 4;
    pixels = malloc(sizeof(*pixels) * buffer_len);
    buffer.pixels = pixels;
    return (buffer);
}

void framebuffer_destroy(framebuffer_t framebuffer)
{
    free(framebuffer.pixels);
    free(framebuffer);
}