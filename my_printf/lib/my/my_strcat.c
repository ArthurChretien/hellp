/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** 
*/

int my_strlen888(char const *str)
{
    int n = 0;

    while (str[n] != '\0') {
        n ++;
    }
    return (n);
}

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = my_strlen888(dest);

    while (src[i] != '\0') {
        dest[j] = src[i];
        i++;
        j++;
    }
    dest[j] = '\0';
    return (dest);
}
