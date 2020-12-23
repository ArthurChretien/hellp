/*
** EPITECH PROJECT, 2020
** my_usage
** File description:
** 
*/
#include "proto.h"

int my_usage_h(void)
{
    my_putstr("animation rendering in a CSFML window.\n");
    my_putchar('\n');
    my_putstr("USAGE\n");
    my_putstr(" ./my_screensaver [OPTIONS] animation_id\n");
    my_putstr(" animation_id     ID of the animation to process");
    my_putstr(" (between 1 and 20).\n");
    my_putchar('\n');
    my_putchar('\n');
    my_putstr("OPTIONS\n");
    my_putstr(" -d               print the description of");
    my_putstr(" all the animations and quit.\n");
    my_putstr(" -h               print the usage and quit.\n");
    my_putchar('\n');
    my_putstr("USER INTERACTIONS\n");
    my_putstr(" LEFT_ARROW       switch to the previous animation.\n");
    my_putstr(" RIGHT_ARROW      switch to the next animation.\n");
    return (0);
}
