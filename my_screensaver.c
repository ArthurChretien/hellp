/*
** EPITECH PROJECT, 2020
** my_screensaver
** File description:
** 
*/
#include <unistd.h>
#include "proto.h"
#include <stdbool.h>

int display_screensaver(int nb)
{
    sfml_components_t sfml_data;
    sfml_data = init_sfml_data(sfml_data);

    if (!sfml_data.wd || !sfml_data.texture)
        return EXIT_FAILURE;
    sfRenderWindow_setFramerateLimit(sfml_data.wd, 30);
    while (sfRenderWindow_isOpen(sfml_data.wd)) {
        sfTexture_updateFromPixels(sfml_data.texture, sfml_data.image->pixels, 800, 600, 0, 0);
        sfSprite_setTexture(sfml_data.sprite, sfml_data.texture, sfTrue);
        while (sfRenderWindow_pollEvent(sfml_data.wd, &sfml_data.event)) {
            if (sfml_data.event.type == sfEvtClosed)
                sfRenderWindow_close(sfml_data.wd);
        }
        sfColor colors = my_colors(rand(), rand(), rand(), 255);
        sfRenderWindow_display(sfml_data.wd);
        draw_line(sfml_data.image, 100, 100, colors);
    }
    clean_all(sfml_data.image, sfml_data.sprite, sfml_data.texture, sfml_data.wd);
}

int main(int ac, char **av)
{
    if (arg_check(ac, av) == 84)
        return (84);
    if (arg_check(ac, av) == 0)
        return (0);
    if (arg_check(ac, av) >= 1 && arg_check(ac, av) <= 3)
        display_screensaver(arg_check(ac, av));
    return (0);
}
