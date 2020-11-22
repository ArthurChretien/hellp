/*
** EPITECH PROJECT, 2020
** get_xmax
** File description:
** 
*/

int get_xmax(char *dest)
{
    int i = 0;
    int j = 0;

    while (dest[i] != '\n' && dest[i] != '\0') {
        i++;
    }
    i++;
    while (dest[i] != '\n' && dest[i] != '\0') {
        i++;
        j++;
    }
    return (j);
}
