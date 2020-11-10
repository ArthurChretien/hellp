/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** 
*/
#include <unistd.h>

int my_strlen(char const *str)
{
    int n = 0;

    while (str[n] != '\0') {
        n ++;
    }
    return (n);
}
