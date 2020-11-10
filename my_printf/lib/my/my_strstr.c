/*
** EPITECH PROJECT, 2020
** my_strstr
** File description:
** 
*/

int my_strlenn(char const *str)
{
    int n = 0;

    while (str[n] != '\0') {
        n ++;
    }
    return (n);
}

char *my_strstr(char *str, char const *to_find)
{
    int n = 0;

    for (int i = 0; i < my_strlenn(str); i++) {
        if (str[i] == to_find[n])
            n++;
        else
            n = 0;
        if (n == my_strlenn(to_find))
            return (str + (i - n) + 1);
    }
    return (0);
}
