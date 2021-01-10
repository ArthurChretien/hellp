/*
** EPITECH PROJECT, 2020
** proto.h
** File description:
** 
*/
#include <SFML/Graphics.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <stdio.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/Window.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

struct anim_t {
    int begin_x;
    int nb_frames;
    float current_frame;
    float speed;
};

struct ground_t {
    sfIntRect ground_rect;
    sfVector2f ground_pos;
    sfTexture *ground_text;
    sfSprite *ground_sprite;
};

struct s_list {
    int y_max;
    int x_max;
    char **tab;
};

struct player_t {
    sfVector2f pos;
    int width;
    int height;
    int speed;
    int jump_height;
    int jump_speed;
    int hitbox;
};

typedef struct gameobjects_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f dir;
    sfIntRect rect;
} gameobjects_t;

sfSprite *set_bg(void);
void my_putstr(char const *str);
void my_putchar(char c);
int my_strcmp(char *s1, char *s2);
void usage(void);
void usage_i(void);
int arg_check(char **av);
sfColor my_colors(sfUint8 r, sfUint8 g, sfUint8 b, sfUint8 a);
int my_get_nbr(char const *str);
char *read_file(const int fd);
int get_xmax(char *dest);
int get_ymax(char *dest);
char **get_tab(struct s_list map, char *dest);
void set_map(char *dest);
int my_strlen(char *str);
int my_getnbr(char const *str);
char *strconc(char *str1, char *str2);
void display_tab(struct s_list map, struct player_t player);
char **fill_tab(struct s_list, char *dest);
struct player_t set_player(void);
int display_game();
bool check_pos(struct player_t player, struct s_list map);
struct ground_t set_ground(void);
struct anim_t set_anim(void);
sfIntRect init_rect(void);