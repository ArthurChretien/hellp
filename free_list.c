/*
** EPITECH PROJECT, 2020
** free_list
** File description:
** 
*/
#include "proto.h"
#include <stddef.h>
#include <stdlib.h>

list *free_list(list *lis)
{
    list *temp = NULL;
    while (lis) {
        temp = lis->next;
        free(lis);
        lis = temp;
    }
    return (lis);
}
