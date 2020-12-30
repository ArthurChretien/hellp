/*
** EPITECH PROJECT, 2020
** init_sfml_data
** File description:
** init_sfml_data
*/
#include "proto.h"

sfml_components_t init_sfml_data(struct sfml_components data, sfVideoMode mode)
{
    data.wd = sfRenderWindow_create(mode, "lol", sfDefaultStyle, NULL);
    data.image = framebuffer_create(800, 600);
    data.tex = sfTexture_create(800, 600);
    data.sprt = sfSprite_create();

    return (data);
}