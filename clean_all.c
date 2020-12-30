/*
** EPITECH PROJECT, 2020
** clean_all
** File description:
** clean_all
*/
#include "proto.h"

void clean_all(framebuffer_t *b, sfSprite *sp, sfTexture *t, sfRenderWindow *wd)
{
    framebuffer_destroy(b);
    sfSprite_destroy(sp);
    sfTexture_destroy(t);
    sfRenderWindow_destroy(wd);
}