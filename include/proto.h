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

typedef struct framebuffer {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
} framebuffer_t;

typedef struct sfml_components {
    sfRenderWindow *wd;
    sfEvent event;
    framebuffer_t *image;
    sfTexture *tex;
    sfSprite *sprt;
} sfml_components_t;

void my_putstr(char const *str);
void my_putchar(char c);
int my_strcmp(char *s1, char *s2);
int my_usage_h(void);
int my_usage_d(void);
int arg_check(int ac, char **av);
sfColor my_colors(sfUint8 r, sfUint8 g, sfUint8 b, sfUint8 a);
void draw_line(framebuffer_t *buffer, sfVector2i a, sfVector2i b);
sfml_components_t init_sfml_data(struct sfml_components data, sfVideoMode mode);
void clean_all(framebuffer_t *b, sfSprite *spr, sfTexture *t, sfRenderWindow *wd);
framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
void framebuffer_destroy(framebuffer_t *framebuffer);
int my_put_pixel(framebuffer_t *fb, unsigned int x, unsigned int y, sfColor c);
int my_get_nbr(char const *str);