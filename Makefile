##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## 
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -I./include
CFLAGS  += -lcsfml-graphics

NAME	= my_screensaver

SRCS	= my_screensaver.c \
	  my_putstr.c \
	  my_putchar.c \
	  my_strcmp.c \
	  my_usage_h.c \
	  my_usage_d.c \
	  arg_check.c \
	  my_colors.c \
	  draw_line.c \
	  my_get_nbr.c \
	  init_sfml_data.c \
	  framebuffer_create.c \
	  clean_all.c \
	  

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean:   clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
