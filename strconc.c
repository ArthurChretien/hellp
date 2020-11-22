/*
** EPITECH PROJECT, 2020
** strconc
** File description:
** 
*/
#include <stdlib.h>
#include "proto.h"

char *strconc(char *str1, char *str2)
{
    char *new_str;
    int i = 0;
    int j = 0;
    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);

    if ((new_str = malloc((len1 + len2 + 1) * sizeof(*new_str))) == NULL)
        return (NULL);
    while (str1[i] != '\0') {
        new_str[i] = str1[i];
        i = i + 1;
    }
    while (str2[j] != '\0') {
        new_str[i] = str2[j];
        i = i + 1;
        j = j + 1;
    }
    new_str[i] = '\0';
    return (new_str);
}
