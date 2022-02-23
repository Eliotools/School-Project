##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile infinAdd
##

SRC     =       main.c

NAME    =       sokoban

LIB     =       -L lib/my/ -l my

CFLAGS  =       -I include

NFLAGS	=		-lncurses

all:    $(NAME)

$(NAME):
		gcc -o $(NAME) -g $(SRC) $(NFLAGS)

clean:
		rm -f *.o
		rm -f *~

fclean:
		rm -f $(NAME)

re:     fclean all
