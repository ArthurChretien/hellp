/*
** EPITECH PROJECT, 2020
** proto
** File description:
** 
*/

struct s_list {
    int y_max;
    int x_max;
    int **tab;

};

char *strconc(char *str1, char *str2);
int my_strlen(char *str);
int my_getnbr(char const *str);    
void my_putchar(char c);
void display_tab(struct s_list data);
int **get_tab(struct s_list data, char *dest);
int get_ymax(char *dest);
int get_xmax(char *dest);
int my_find_min(int up, int left, int upleft);
int **replace_by_neg_bis(struct s_list data, int res, int x, int y);
