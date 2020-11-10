/*
** EPITECH PROJECT, 2020
** my_strncat
** File description:
** 
*/

int my_strlen999(char const *str)
{
    int n = 0;

    while (str[n] != '\0') {
        n ++;
    }
    return (n);
}

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int j = my_strlen999(dest);

    while (src[i] != '\0' && i < nb) {
        dest[j] = src[i];
        i++;
        j++;
    }
    dest[j] = '\0';
    return (dest);
}
