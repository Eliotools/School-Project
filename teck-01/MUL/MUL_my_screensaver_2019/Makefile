##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile infinAdd
##

SRC     =       new.c

NAME    =       my_screensaver

LIB     =       -L lib/my/ -l my

CFLAGS  =       -I include

SFMLFLAGS =  -l csfml-graphics -l csfml-system -l csfml-audio

all:    $(NAME)

$(NAME):
				gcc -o $(NAME) $(SRC) $(SFMLFLAGS)

clean:
		rm -f *.o
		rm -f *~

fclean:
		rm -f $(NAME)

re:     fclean all
