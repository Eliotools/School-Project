##
## EPITECH PROJECT, 2021
## B-FUN-300-LIL-3-1-funPoolDay2-antoine.degeeter
## File description:
## Makefile
##

SRC	=	swapchecker.hs	\

NAME = pushswap_checker

 
all:	$(NAME)

$(NAME):	$(OBJ)
		ghc -o $(NAME) $(SRC) -Wall -Wextra

clean:
	$(RM) *.hi
	$(RM) *.o

fclean:	clean
	$(RM)	$(NAME)

re:	fclean	all
