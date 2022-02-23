##
## EPITECH PROJECT, 2021
## B-FUN-300-LIL-3-1-funPoolDay2-antoine.degeeter
## File description:
## Makefile
##

SRC	=	204ducks.hs	\

NAME = 204ducks

 
all:	$(NAME)

$(NAME):	$(OBJ)
		ghc -o $(NAME) $(SRC)

clean:
	$(RM) *.hi
	$(RM) *.o

fclean:	clean
	$(RM)	$(NAME)

re:	fclean	all
