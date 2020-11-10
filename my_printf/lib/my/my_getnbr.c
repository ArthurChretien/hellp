/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** 
*/

int my_getnbr(char const *str)
{
    int i = 0;
    int value = 0;
    int c = 1;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            value = value + str[i] - 48;
            value = value * 10;
        }
        if (str[i-1] == '-')
            c = c * -1;
        i++;
    }
    value = value / 10;
    return (value * c);
}
