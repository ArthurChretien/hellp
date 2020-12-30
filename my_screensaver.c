/*
** EPITECH PROJECT, 2020
** my_screensaver
** File description:
** my_screensaver
*/
#include <unistd.h>
#include "proto.h"
#include <stdbool.h>

int display_screensaver() //int nb)
{
    sfml_components_t sfml_data;
    sfVideoMode mode = {800, 600, 32};
    sfml_data = init_sfml_data(sfml_data, mode);
    sfVector2i a = {100, 120};
    sfVector2i b = {300, 500};

    if (!sfml_data.wd || !sfml_data.tex)
        return EXIT_FAILURE;
    sfRenderWindow_setFramerateLimit(sfml_data.wd, 30);
    while (sfRenderWindow_isOpen(sfml_data.wd)) {
        sfTexture_updateFromPixels(sfml_data.tex,
        sfml_data.image->pixels, 800, 600, 0, 0);
        sfSprite_setTexture(sfml_data.sprt, sfml_data.tex, sfTrue);
        while (sfRenderWindow_pollEvent(sfml_data.wd, &sfml_data.event)) {
            if (sfml_data.event.type == sfEvtClosed)
                sfRenderWindow_close(sfml_data.wd);
        }
        //sfColor colors = my_colors(rand(), rand(), rand(), 255);
        sfRenderWindow_display(sfml_data.wd);
        draw_line(sfml_data.image, a, b);
    }
    clean_all(sfml_data.image, sfml_data.sprt, sfml_data.tex, sfml_data.wd);
    return (0);
}

int main(int ac, char **av)
{
    if (arg_check(ac, av) == 84)
        return (84);
    if (arg_check(ac, av) == 0)
        return (0);
    if (arg_check(ac, av) >= 1 && arg_check(ac, av) <= 3)
        display_screensaver();//arg_check(ac, av));
    return (0);
}
