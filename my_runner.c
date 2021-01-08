/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** my_runner
*/

#include "proto.h"

int display_game()
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "", sfResize | sfClose, NULL);
    sfSprite *bg = set_bg();
    sfEvent event;

    if (!window)
        return EXIT_FAILURE;
    sfRenderWindow_setFramerateLimit(window, 30);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, bg, NULL);
        sfRenderWindow_display(window);
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
    printf("%d\n", 2);
    set_map(dest);
    return (0);
}