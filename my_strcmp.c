/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** 
*/

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] != 0 && s2[i] != 0 && s1[i] == s2[i]) {
        i++;
    }
    return (s1[i] - s2[i]);
}
