/*
** EPITECH PROJECT, 2021
** read_map
** File description:
** read_map
*/
#include "proto.h"

int get_xmax(char *dest)
{
    int i = 0;

    while (dest[i] != '\n') {
        i++;
    }
    return (i);
}

int get_ymax(char *dest)
{
    int i = 0;
    int j = 1;

    while (dest[i] != '\0') {
        if (dest[i] == '\n')
            j++;
        i++;
    }
    return (j);
}

char **fill_tab(struct s_list map, char *dest)
{
    map.tab = get_tab(map, dest);
    int i = 0;
    int y = 0;
    int x = 0;

    for (; dest[i] != '\0'; i++, x++) {
        if (dest[i] == '\n') {
            y++;
            x = 0;
        }
        map.tab[y][x] = dest[i];
    }
    return (map.tab);
}

char **get_tab(struct s_list map, char *dest)
{
    int y = 0;
    int n = 0;

    map.tab = malloc(sizeof(char *) * (map.y_max + 1));
    map.tab[y] = malloc(sizeof(char) * (map.x_max + 1));
    for (; dest[n] != '\0'; n++) {
        if (dest[n] == '\n') {
            y++;
            map.tab[y] = malloc(sizeof(char) * (map.x_max + 1));
        }
    }
    return (map.tab);
}

char *read_file(const int fd)
{
    char *buffer = "";
    char *dest = "";
    int size = 1000;
    int read_len = 0;

    if ((buffer = malloc((size + 1) * sizeof(char))) == NULL)
        return (NULL);
    while ((read_len = read(fd, buffer, size)) > 0) {
        buffer[read_len] = '\0';
        dest = strconc(dest, buffer);
    }
    return (dest);
}