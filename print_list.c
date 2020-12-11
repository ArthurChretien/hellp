/*
** EPITECH PROJECT, 2020
** print_list
** File description:
** 
*/
#include "proto.h"

void print_list(list *lis)
{
    while (lis) {
        printf("%d", lis->data);
        printf("%s", " ");
        lis = lis->next;
    }
}
