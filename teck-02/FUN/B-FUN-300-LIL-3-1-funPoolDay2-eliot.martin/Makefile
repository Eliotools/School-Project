##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Moi
##

SRC     =		DoOp.hs	\

NAME    =		doop

all:    		$(NAME)

$(NAME):
				ghc -o $(NAME) $(SRC)

clean:
				rm -f *.o
				rm -f *.hi
				rm -f *~

fclean:
				make clean
				rm -f $(NAME)
				ls

re:				fclean all