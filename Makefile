##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## 
##

CC      = gcc

RM      = rm -f

CFLAGS  += -Wall -Wextra -Werror
CFLAGS  += -I/.include

LDFLAGS =

NAME    = libmy.a

SRCS    = lib/my/my_printf.c \
          lib/my/my_print_octal.c \
          lib/my/my_print_hexa.c \
          lib/my/my_print_hexamaj.c \
          lib/my/my_putchar.c \
          lib/my/my_putnbr.c \
          lib/my/my_putstr.c \
          lib/my/my_print_binary.c \
          lib/my/my_print_unchar.c \
	  lib/my/my_print_nonprintable.c \

OBJS    = $(SRCS:.c=.o)

all:      $(NAME)

$(NAME):  $(OBJS)
          ar rc $(NAME) $(OBJS)
          ranlib $(NAME)

clean:
          $(RM) $(OBJS)

fclean:   clean
          $(RM) $(NAME)

re:       fclean all

.PHONY:all clean fclean re
