##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## 
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -I./include

NAME	= push_swap

SRCS	= push_swap.c \
	  add_at_position.c \
	  create_cell.c \
	  list_is_empty.c \
	  print_list.c \
	  free_list.c \
	  my_getnbr.c \
	  check_arg.c \
	  swap_l_a.c \

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
