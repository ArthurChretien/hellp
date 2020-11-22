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

int **get_tab(struct s_list data, char *dest)
{
    int y = 0;
    int x = 0;
    int n = 0;
    
    data.tab = malloc(sizeof(int *) * (data.y_max + 1));
    data.tab[y] = malloc(sizeof(int) * (data.x_max + 1));
    while (dest[n] != '\n' && dest[n] != '\0')
        n++;
    n++;
    for(; dest[n] != '\0'; n++)
    {
        if (dest[n] == '\n') {
            y++;
            x = 0;
            data.tab[y] = malloc(sizeof(int) * (data.x_max + 1));
        }
        else if (dest[n] == '.')
            data.tab[y][x++] = 1;
        else
            data.tab[y][x++] = 0;
    }
    return (data.tab);
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

int **replace_by_neg_bis(struct s_list data, int res, int x, int y)
{
    int j = y - (res - 1);
    int i = x - (res - 1);

    for (; j <= y; j++) {
        i = x - (res - 1);
        for (; i <= x; i++) {
            data.tab[j][i] = -1;
        }
    }
    return (data.tab);
}

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

int  **my_find_bsq(struct s_list data)
{
    int x = 0;
    int y = 0;
    int res = 0;

    for (;y < data.y_max; y++) {
        x = 0;
        for (;x < data.x_max; x++) {
            if (data.tab[y][x] > 0 && x != 0 && y != 0) {
                data.tab[y][x] = 1 + my_find_min(data.tab[y][x - 1], data.tab[y - 1][x], data.tab[y - 1][x - 1]);
            }
            if (data.tab[y][x] > res)
                res = data.tab[y][x];
        }
    }
    //tmp_aff(data);
    data.tab = replace_by_neg(data, res);
    return (data.tab);
}

int bsq(char *dest)
{
    struct s_list data;

    data.x_max = get_xmax(dest);
    data.y_max = get_ymax(dest);
    data.tab = get_tab(data, dest);
    data.tab = my_find_bsq(data);
    display_tab(data);
    
    int y = 0; 
    while (y != data.y_max) {
        free(data.tab[y]);
        y++;
    }
    free(data.tab);
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
