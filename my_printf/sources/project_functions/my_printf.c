/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** 
*/
#include <stdarg.h>
#include <unistd.h>
#include "my.h"
#include "prototypes.h"

void target_flags(char flag, va_list *my_l)
{
    switch (flag) {
    case 'd':
        my_put_nbr(va_arg(*my_l, int));
        break;
    case 'c':
        my_putchar(va_arg(*my_l, int));
        break;
    case 's':
        my_putstr(va_arg(*my_l, char*));
        break;
    case 'i':
        my_put_nbr(va_arg(*my_l, int));
        break;
    case 'o':
        //my_print_octal(va_arg(*my_l, int));
        break;
    default :
        target_flags2(flag, &my_l);
    }
}

void target_flags2(char flag, va_list *my_l)
{
    switch (flag) {
    case 'u':
        //my_print_unchar(va_arg(*my_l, int));
        break;
    case 'x':
        //my_print_hexa(va_arg(*my_l, int));
    case 'X':
        //my_print_hexamaj(va_arg(*my_l, int));
    case '%':
        my_putchar('%');
        break;
    case 'b':
        //my_print_binary(va_arg(*my_l, int));
        break;
    case 'S':
        //my_printf_nonprintable(va_arg(*my_l, char*));
        break;
    }
}

void my_printf(char *src, ...)
{
    va_list my_l;
    int i = 0;

    va_start(my_l, src);
    while (src[i] != 0) {
        if (i != 0 && src[i - 1] == '%')
            target_flags(src[i], &my_l);
        i++;
    }
}

void main(void)
{
    my_printf("%d", 200);
    my_putchar('\n');
    printf("%d", 200);
}