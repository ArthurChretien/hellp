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
        printf("%d", i);
    }
    return (i);
}

int get_ymax(char *dest)
{
    int i = 0;
    int j = 0;

    while (dest[i] != '\0') {
        i = 0;
        while (dest[i] != '\n') {
            i++;
        }
        i++;
        j++;
    }
    return (j);
}

char **get_tab(struct s_list map, char *dest)
{
    int y = 0;
    int n = 0;

    printf("%d\n", 3);
    map.tab = malloc(sizeof(char *) * (map.y_max + 1));
    printf("%d\n", 4);
    map.tab[y] = malloc(sizeof(char) * (map.x_max + 1));
    printf("%d\n", 5);

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
    int size = 10000;
    int read_len = 0;

    if ((buffer = malloc((size + 1) * sizeof(char))) == NULL)
        return (NULL);
    printf("%d\n", 0);
    while ((read_len = read(fd, buffer, size)) > 0) {
        buffer[read_len] = '\0';
        dest = strconc(dest, buffer);
    }
    printf("%d\n", 1);
    return (dest);
}