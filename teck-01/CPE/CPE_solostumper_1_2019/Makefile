##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Moi
##

SRC     =	tristgoritme.c


NAME    =       trisant

OBJ 	= 	$(SRC:.c=.o)

LIB     =       -L./lib/phoenix -lphoenix

CFLAGS  =       -I./include -Wall -Wextra -g

all:    	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/phoenix
	gcc -o $(NAME) $(OBJ) $(LIB) $(CFLAGS)

clean:
	make clean -C lib/phoenix
	rm -f *.o
	rm -f *~

fclean:
	make -C lib/phoenix fclean
	make clean
	rm -f $(NAME)
	ls

re:	fclean all
