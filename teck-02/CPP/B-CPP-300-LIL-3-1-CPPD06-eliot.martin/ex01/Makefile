##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Moi
##

SRC     =	main.c	\

NAME    =	my_convert_temp

OBJ 	= 	$(SRC:.c=.o)

CFLAGS  =       -Wall -Wextra -W

all:    		$(NAME)

$(NAME):		$(OBJ)
				g++ -o $(NAME) $(OBJ)

clean:
				rm -f *.o
				rm -f *~

fclean:
				make clean
				rm -f $(NAME)

re:				fclean all
