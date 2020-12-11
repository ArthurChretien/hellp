/*
** EPITECH PROJECT, 2020
** proto.h
** File description:
** 
*/

typedef struct cell_t
{
    int            data;
    struct cell_t *next;
}list, cell;

cell *create_cell(int data);
int list_is_empty(list *lis);
list *add_at_position(list *lis, int data, int pos);
void print_list(list *lis);
list *free_list(list *lis);
int my_getnbr(char const *str);    
int check_arg(int ac, char **av);    
void swap_l_a(list *l_a);
    
