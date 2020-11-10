/*
** EPITECH PROJECT, 2020
** my_swap
** File description:
** 
*/
#include <unistd.h>

void my_swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}
