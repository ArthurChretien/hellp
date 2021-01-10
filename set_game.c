/*
** EPITECH PROJECT, 2021
** set_bg
** File description:
** set_bg
*/
#include "proto.h"

struct anim_t set_anim(void)
{
    struct anim_t anim;
    anim.begin_x = 20;
    anim.nb_frames = 6;
    anim.current_frame = 0;
    anim.speed = 4;

    return (anim);
}

struct ground_t set_ground(void)
{
    struct ground_t g;
    sfIntRect rect = {0, 0, 200, 100};
    g.ground_rect = rect;
    sfVector2f ground_pos = {0, 500};
    g.ground_pos = ground_pos;
    g.ground_text = sfTexture_createFromFile("ground.png", &g.ground_rect);
    g.ground_sprite = sfSprite_create();
    sfSprite_setTexture(g.ground_sprite, g.ground_text, true);
    sfSprite_setPosition(g.ground_sprite, g.ground_pos);
    return (g);
}

void set_map(char *dest)
{
    struct s_list map;

    map.x_max = get_xmax(dest);
    map.y_max = get_ymax(dest);
    map.tab = fill_tab(map, dest);
    display_game(map);
}

struct player_t set_player(void)
{
    struct player_t player;

    player.pos.x = 3;
    player.pos.y = 9;
    player.width = 1;
    player.height = 1;
    player.speed = 1;
    return (player);
}

sfSprite *set_bg(void)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("BACKGROUND.png", NULL);
    sfSprite_setTexture(sprite, texture, false);
    return (sprite);
}