/*
** EPITECH PROJECT, 2021
** usage
** File description:
** usage
*/

#include "proto.h"

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] != 0 && s2[i] != 0 && s1[i] == s2[i]) {
        i++;
    }
    return (s1[i] - s2[i]);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char const *str)
{
    int n = 0;

    while (str[n] != '\0') {
        my_putchar(str[n]);
        n++;
    }
    return;
}

void usage(void)
{
    my_putstr("Finite runner created with CSFML.\n");
    my_putchar('\n');
    my_putstr("USAGE\n");
    my_putstr(" ./my_runner map.txt\n");
    my_putstr(" animation_id     ID of the animation to process");
    my_putstr(" (between 1 and 20).\n");
    my_putchar('\n');
    my_putchar('\n');
    my_putstr("OPTIONS\n");
    my_putstr(" -i               launch the game in infinite mode.\n");
    my_putstr(" -h               print the usage and quit.\n");
    my_putchar('\n');
    my_putstr("USER INTERACTIONS\n");
    my_putstr(" SPACE_KEY       jump.\n");
}

void usage_i(void)
{
   // lauch game in infinite mode
}