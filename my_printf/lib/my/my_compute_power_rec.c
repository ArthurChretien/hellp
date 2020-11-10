/*
** EPITECH PROJECT, 2020
** my_compute_power_rec
** File description:
** 
*/
#include <unistd.h>

int my_compute_power_rec(int nb, int p)
{
    int b;

    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    if (p == 1)
        return (nb);
    b = nb * my_compute_power_rec(nb, p - 1);
    return (b);
}
