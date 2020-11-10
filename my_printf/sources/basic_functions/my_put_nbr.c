/*
** EPITECH PROJECT, 2020
** my_put_nbr.c
** File description:
** 
*/
#include "my.prototypes.h"

void print_intmin(void)
{
    my_putchar('-');
    my_putchar('2');
    my_putchar('1');
    my_putchar('4');
    my_putchar('7');
    my_putchar('4');
    my_putchar('8');
    my_putchar('3');
    my_putchar('6');
    my_putchar('4');
    my_putchar('8');
}
void my_put_nbr(va_arg(*my_l, int nb))
{
    int temp = 0;

    if (nb == -2147483648) {
        print_intmin();
        break;
    }
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
        my_put_nbr(nb);
    }
    if (nb >= 10) {
        temp = nb % 10;
        nb = nb /10;
        my_put_nbr(nb);
        my_putchar(temp + '0');
    } else
        my_putchar(nb + '0');
}
