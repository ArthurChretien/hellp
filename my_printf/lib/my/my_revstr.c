/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** 
*/

int my_strlen4(char const *str)
{
    int n = 0;

    while (str[n] != '\0') {
        n ++;
    }
    return (n);
}

char *my_revstr(char *str)
{
    int read = 0;
    char temp;
    int i = my_strlen4(str) -1;

    while (i > read) {
        temp = str[read];
        str[read] = str[i];
        str[i] = temp;
        read++;
        i--;
    }
    return (str);
}
