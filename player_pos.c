/*
** EPITECH PROJECT, 2021
** player_pos
** File description:
** player_pos
*/
#include "proto.h"

bool check_pos(struct player_t player, struct s_list map)
{
    int x = (int)player.pos.x;
    int y = (int)player.pos.y;

    if (map.tab[y][x + 1] == '2')
        return FALSE;
    if (map.tab[y + 1][x] == '2')
        return FALSE;
    return TRUE;
}