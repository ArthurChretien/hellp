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
#include <stdio.h>

struct s_list {
    int y_max;
    int x_max;
    int **tab;

};

void display_tab(struct s_list data)
{
    int x = 0;
    int y = 0;

    while (y != data.y_max) {
        x = 0;
        while (x != data.x_max) {
            if (data.tab[y][x] > 0)
                my_putchar('.');
            else if (data.tab[y][x] < 0)
                my_putchar('x');
            else
                my_putchar('o');
            x++;
        }
        my_putchar('\n');
        y++;
    }
}

int get_xmax(char *dest)
{
    int i = 0;
    int j = 0;

    while (dest[i] != '\n' && dest[i] != '\0') {
        i++;
    }
    i++;
    while (dest[i] != '\n' && dest[i] != '\0') {
        i++;
        j++;
    }
    return (j);
}

int get_ymax(char *dest)
{
    int n = 0;
    char *temp;

    while (dest[n] != '\n') {
        n++;
    }
    temp = malloc(sizeof(char) * n);
    n = 0;
    while (dest[n] != '\n') {
        temp[n] = dest[n];
        n++;
    }
    temp[n] = '\0';
    return (my_getnbr(temp));
}

struct s_list get_tab(char *dest)
{
    struct s_list data;
    int y = 0;
    int n = 0;
    int x = 0;

    data.x_max = get_xmax(dest);
    data.y_max = get_ymax(dest);
    data.tab = malloc(sizeof(int *) * data.y_max);
    data.tab[y] = malloc(sizeof(int) * data.x_max);
    while (dest[n] != '\0') {
        if (dest[n] == '\n') {
            y++;
            x = 0;
            data.tab[y] = malloc(sizeof(int) * data.x_max);
        }
        else if (dest[n] == '.') {
            data.tab[y][x++] = 1;
        }
        else {
            data.tab[y][x++] = 0;
        }
        n++;
    }
    return (data);
}

int my_find_min(int up, int left, int upleft)
{
    int min;

    if (up < left)
        min = up;
    else
        min = left;
    if (upleft < min)
        min = upleft;
    return (min);
}

struct s_list replace_by_neg_bis(struct s_list data, int res, int x, int y)
{
    int j = y - (res - 1);
    int i = x - (res - 1);

    for (; j < y; j++) {
        i = x - (res - 1);
        for (; i < x; i++) {
            data.tab[j][i] = -1;
        }
    }
    return (data);
}

struct s_list replace_by_neg(struct s_list data, int res)
{
    int x = 0;
    int y = 0;

    for (;y < data.y_max; y++) {
        for (;x < data.x_max; x++) {
            if (data.tab[y][x] == res)
                data = replace_by_neg_bis(data, res, x, y);
        }
    }
    return (data);
}

int get_specific_case(int **tab, int x, int y)
{
    int cell;

    if (x == 0)
        cell = 1 + tab[y - 1][x];
    else if (y == 0)
        cell = 1 + tab[y][x - 1];
    else
        cell = 1 + my_find_min(tab[y][x - 1], tab[y - 1][x], tab[y - 1][x - 1]);
    return (cell);
}

struct s_list my_find_bsq(struct s_list data)
{
    int x = 0;
    int y = 0;
    int res = 0;

    for (;y < data.y_max; y++) {
        for (;x < data.x_max; x++) {
            if (data.tab[y][x] > 0 && (x != 0 || y != 0))
                data.tab[y][x] = get_specific_case(data.tab, x, y);
            if (data.tab[y][x] > res)
                res = data.tab[y][x];
        }
    }
    data = replace_by_neg(data, res);
    return (data);
}

int bsq(char *dest)
{
    struct s_list data = get_tab(dest);
    printf("\n\n\n\n");
    display_tab(data);
    printf("\n\n\n\n");
    data = my_find_bsq(data);
    display_tab(data);
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