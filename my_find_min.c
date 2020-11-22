/*
** EPITECH PROJECT, 2020
** my_find_min
** File description:
** 
*/

int my_find_min(int up, int left, int upleft)
{
    int min;

    if (up < left)
        min = up;
    else
        min = left;
    if (upleft < min)
        min = upleft;
    return (min);
}
