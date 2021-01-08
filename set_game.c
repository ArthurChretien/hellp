/*
** EPITECH PROJECT, 2021
** set_bg
** File description:
** set_bg
*/
#include "proto.h"

void set_map(char *dest)
{
    struct s_list map;

    map.x_max = get_xmax(dest);
    map.y_max = get_ymax(dest);
    map.tab = get_tab(map, dest);
    display_tab(map);
}

struct player_t set_player(void)
{
    struct player_t player;

    player.pos.x = 100;
    player.pos.y = 100;
    player.width = 53;
    player.height = 85;
    return (player);
}

sfSprite *set_bg(void)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("BACKGROUND.png", NULL);
    sfSprite_setTexture(sprite, texture, false);
    return (sprite);
}