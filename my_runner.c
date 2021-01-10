/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** my_runner
*/

#include "proto.h"

int display_game(struct s_list map)
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "", sfResize | sfClose, NULL);
    sfSprite *bg = set_bg();
    struct player_t player = set_player();
    struct ground_t g = set_ground();
    struct anim_t anim = set_anim();
    sfIntRect rect = init_rect();
    sfEvent event;
    float gravity = 0.25;
    float time_elapsed;
    sfClock *clock = sfClock_create();

    if (!window)
        return EXIT_FAILURE;
    sfRenderWindow_setFramerateLimit(window, 30);
    sfClock_restart(clock);
    while (sfRenderWindow_isOpen(window)) {
        time_elapsed = sfClock_getElapsedTime(clock).microseconds /100000;
        anim.current_frame += time_elapsed * anim.speed;
        rect.left = anim.begin_x + rect.width *(int) anim.current_frame;
        if (anim.current_frame >= anim.nb_frames)
            anim.current_frame = 0;
        sfClock_restart(clock);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            else if (event.type == sfEvtKeyPressed) {
                if (event.key.code == sfKeySpace) {
                    if (player.pos.y == 9)
                        player.pos.y -= 4;
                }
                if (event.key.code == sfKeyQ) {
                    player.pos.x -= 1;
                }
                if (event.key.code == sfKeyD) {
                    player.pos.x += 1;
                }
            }
        }
        if (check_pos(player, map) == FALSE) {
            printf("\n%s", "YOU DIED !");
            return (0);
        }
        if (map.tab[(int)player.pos.y + 1][(int)player.pos.x] != '1')
            player.pos.y = player.pos.y + gravity;
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, bg, NULL);
        sfRenderWindow_drawSprite(window, g.ground_sprite, NULL);
        sfRenderWindow_display(window);
        display_tab(map, player);
    }
    return (0);
}

int main(int ac, char **av)
{
    char *dest;
    int fd;

    if (ac != 2) {
        my_putstr("./my_screensaver: bad arguments:");
        my_putstr(" 0 given but 1 is required\n");
        my_putstr("retry with -h\n");
        return (84);
    }
    if (arg_check(av) == 0)
        return (0);
    fd = open(av[1], O_RDONLY);
    if ((dest = read_file(fd)) == NULL)
        return (84);
    set_map(dest);
    return (0);
}