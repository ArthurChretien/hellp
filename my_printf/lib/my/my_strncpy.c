/*
** EPITECH PROJECT, 2020
** my_strncpy
** File description:
** 
*/

int my_strlen9(char const *str)
{
    int n = 0;

    while (str[n] != '\0') {
        n ++;
    }
    return (n);
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int read = 0;

    while ((src[read] != '\0') && (read < n)) {
        dest[read] = src[read];
        read++;
    }
    if (n > my_strlen9(src))
        dest[read] = '\0';
    return (dest);
}
