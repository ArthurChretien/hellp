/*
** EPITECH PROJECT, 2020
** add_at_position
** File description:
** 
*/
#include "proto.h"

list *add_at_position(list *lis, int data, int pos)
{
    list *prev = lis;
    list *curr = lis;
    int i = 0;
    cell *cell = create_cell(data);

    if (list_is_empty(lis))
        return (cell);
    if (pos == 0) {
        cell->next = lis;
        return cell;
    }
    while (i < pos) {
        prev = curr;
        curr = curr->next;
        i++;
    }
    prev->next = cell;
    cell->next = curr;
    return (lis);
}
