/*
** EPITECH PROJECT, 2021
** util
** File description:
** util
*/
#include "proto.h"

char *strconc(char *str1, char *str2)
{
    char *new_str;
    int i = 0;
    int j = 0;
    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);

    if ((new_str = malloc((len1 + len2 + 1) * sizeof(*new_str))) == NULL)
        return (NULL);
    while (str1[i] != '\0') {
        new_str[i] = str1[i];
        i = i + 1;
    }
    while (str2[j] != '\0') {
        new_str[i] = str2[j];
        i = i + 1;
        j = j + 1;
    }
    new_str[i] = '\0';
    return (new_str);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int value = 0;
    int c = 1;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            value = value + str[i] - 48;
            value = value * 10;
        }
        if (str[i-1] == '-')
            c = c * -1;
        i++;
    }
    value = value / 10;
    return (value * c);
}

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

void display_tab(struct s_list map)
{
    int x = 0;
    int y = 0;

    while (y != map.y_max) {
        x = 0;
        while (x != map.x_max) {
            my_putchar(map.tab[y][x]);
            x++;
        }
        my_putchar('\n');
        y++;
    }
}