##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC     =       main.c          \
		rush3.c		\
		my_print_b.c

OBJ     =       $(SRC:.c=.o)

CFLAGS  =       -L./lib/my -g -W -Wall -Wextra -I./include/

NAME    =       rush3

all: $(NAME)

$(NAME): $(OBJ)
		make -C ./lib/my
		gcc $(OBJ) $(CFLAGS) -o $(NAME) -lmy

clean:
		rm -f $(OBJ)
		rm -rf ./lib/my/*.o
		rm -rf ./lib/my/libmy.a

fclean: clean
		rm -f $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
