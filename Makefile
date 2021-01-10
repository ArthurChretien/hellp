##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -I./include -Wall -Werror -Wextra
CFLAGS  += -lcsfml-graphics
CFLAGS  += -lcsfml-system

NAME	= my_runner

SRCS	= my_runner.c \
	  usage.c \
	  arg_check.c \
	  gameobjects_create.c \
	  set_game.c \
	  read_map.c \
	  util.c \
	  player_pos.c \
	  init_rect.c \

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
