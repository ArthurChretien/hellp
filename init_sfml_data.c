/*
** EPITECH PROJECT, 2020
** init_sfml_data
** File description:
** init_sfml_data
*/
#include "proto.h"

sfml_components_t init_sfml_data(struct sfml_components data)
{
    data.mode = {800, 600, 32};
    data.wd = sfRenderWindow_create(mode, "", sfDefaultStyle, NULL);
    data.event;
    data.image = framebuffer_create(800, 600);
    data.texture = sfTexture_create(800, 600);
    data.sprite = sfSprite_create();

    return (data);
}