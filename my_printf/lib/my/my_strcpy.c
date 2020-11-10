/*
** EPITECH PROJECT, 2020
** my_strncpy
** File description:
** 
*/
#include <unistd.h>

char *my_strcpy(char *dest, char const *src)
{
    int read = 0;

    while (src[read] != '\0') {
        dest[read] = src[read];
        read++;
    }
    dest[read] = '\0';
    return (dest);
}
