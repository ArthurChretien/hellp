/*
** EPITECH PROJECT, 2020
** clean_all
** File description:
** clean_all
*/
#include "proto.h"

void clean_all(framebuffer_t *b, sfSprite *spr, sfTexture *t, sfRenderWindow *wd)
{
    framebuffer_destroy(b);
    sfSprite_destroy(spr);
    sfTexture_destroy(t);
    sfRenderWindow_destroy(wd);
    free(b.pixels);
    free(b);
}