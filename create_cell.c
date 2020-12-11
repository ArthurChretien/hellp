/*
** EPITECH PROJECT, 2020
** create_cell
** File description:
** 
*/
#include "proto.h"
#include <stdlib.h>

cell *create_cell(int data)
{
    cell *cell = malloc(sizeof(cell));

    if (!cell)
        return NULL;
    cell->data = data;
    cell->next = NULL;
    return (cell);
}

