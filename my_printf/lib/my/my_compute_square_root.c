/*
** EPITECH PROJECT, 2020
** my_compute_square_root
** File description:
** 
*/
#include <unistd.h>

int my_compute_square_root(int nb)
{
    int a = 1;

    if (nb <= 0)
        return (0);
    while (a * a != nb) {
        if (a > nb)
            return (0);
        else
            a++;
    }
    return (a);
}
