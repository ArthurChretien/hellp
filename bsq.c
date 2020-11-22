/*
** EPITECH PROJECT, 2020
** bsq
** File description:
** 
*/
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "proto.h"

int **replace_by_neg(struct s_list data, int res)
{
    int x = 0;
    int y = 0;

    for (;y < data.y_max; y++) {
        x = 0;
        for (;x < data.x_max; x++) {
            if (data.tab[y][x] == res) {
                return (replace_by_neg_bis(data, res, x, y));
            }
        }
    }
    return (data.tab);
}

int **my_find_bsq(struct s_list data)
{
    int x = 0;
    int y = 0;
    int res = 0;

    for (;y < data.y_max; y++) {
        x = 0;
        for (;x < data.x_max; x++) {
            if (data.tab[y][x] > 0 && x != 0 && y != 0) {
                data.tab[y][x] = 1 + my_find_min(data.tab[y][x - 1],
                data.tab[y - 1][x], data.tab[y - 1][x - 1]);
            }
            if (data.tab[y][x] > res)
                res = data.tab[y][x];
        }
    }
    data.tab = replace_by_neg(data, res);
    return (data.tab);
}

int bsq(char *dest)
{
    struct s_list data;
    int y = 0;

    data.x_max = get_xmax(dest);
    data.y_max = get_ymax(dest);
    data.tab = get_tab(data, dest);
    data.tab = my_find_bsq(data);
    display_tab(data);
    while (y != data.y_max) {
        free(data.tab[y]);
        y++;
    }
    free(data.tab);
    free(dest);
    return (0);
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

int main(int ac, char **av)
{
    char *dest;
    int fd;

    if (ac != 2)
        return (84);
    fd = open(av[1], O_RDONLY);
    if ((dest = read_file(fd)) == NULL)
        return (84);
    bsq(dest);
    return (0);
}
