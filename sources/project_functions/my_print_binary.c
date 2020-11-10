/*
** EPITECH PROJECT, 2020
** my_print_binary
** File description:
** 
*/
#include "my.h"

void my_print_binary(va_arg(*my_l, int nb))
{
    int result = 0;

    if (nb >= 2) {
        result = nb % 2;
        nb = nb / 2;
        my_print_binary(nb);
    }
    if (nb > 0) {
        result = nb % 2;
        nb = nb / 2;
    }
    result = result + '0';
    my_putchar(result);
}
