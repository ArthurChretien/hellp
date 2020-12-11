/*
** EPITECH PROJECT, 2020
** swap_l_b
** File description:
** 
*/
#include "proto.h"
#include <stddef.h>

void swap_l_b(list *l_b)
{
    list *prev = NULL;
    list *temp;

    temp = l_b->next->next;
    l_b->next->next = l_b->next;
    l_b->next = temp;
}
