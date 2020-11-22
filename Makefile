##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## 
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -I./include
CFLAGS	+= -Wall -Werror -Wextra

NAME	= bsq

SRCS	= bsq.c \
	  my_strlen.c \
	  my_putchar.c \
	  strconc.c \
	  my_getnbr.c \
	  display_tab.c \
	  get_tab.c \
	  get_xmax.c \
	  get_ymax.c \
	  my_find_min.c \
	  replace_by_neg_bis.c \

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:   clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
