/*
** EPITECH PROJECT, 2020
** swap_l_a
** File description:
** 
*/
#include "proto.h"
#include <stddef.h>

void swap_l_a(list *l_a)
{
    list *temp = NULL;

    temp = l_a;
    l_a = l_a->next;
    temp->next = l_a->next;
    l_a->next = temp;    
/*    temp = l_a->next;
    l_a->next = l_a->next->next;
    temp->next = l_a;
    l_a = temp;
/*    temp = l_a;
    l_a = (l_a)->next;
    temp->next = (l_a)->next;
    l_a->next = temp;
*/
}
