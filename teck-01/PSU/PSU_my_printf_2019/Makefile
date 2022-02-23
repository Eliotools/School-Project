##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC     =       main.c 		\
				flag_a.c 	\
				flag_b.c 	\
				my_next.c 	\

OBJ     =       $(SRC:.c=.o)

CFLAGS  =       -L./lib/my -g -W -Wall -Wextra -I./include/ -lmy

NAME    =       printf

all: $(NAME)

$(NAME): $(OBJ)
		make -C ./lib/my
		gcc $(OBJ) $(CFLAGS) -o $(NAME)

clean:
		rm -f $(OBJ)
		rm -rf ./lib/my/*.o
		rm -rf ./lib/my/libmy.a

fclean: clean
		rm -f $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
