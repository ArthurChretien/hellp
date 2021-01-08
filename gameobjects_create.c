/*
** EPITECH PROJECT, 2021
** gameobjects_create
** File description:
** gameobjects_create
*/
#include "proto.h"

gameobjects_t gameobjects_create(sfTexture *text, int x, int y, sfIntRect rect)
{
    gameobjects_t *obj;

    obj = malloc(sizeof(*obj));
    obj->sprite = sfSprite_create();
    obj->texture = text;
    obj->pos.x = x;
    obj->pos.y = y;
    obj->dir.x = 0;
    obj->dir.y = 0;
    obj->rect = rect;
    sfSprite_setTexture(obj->sprite, obj-> texture, sfFalse);
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    sfSprite_setPosition(obj->sprite, obj->pos);
    return (*obj);
}