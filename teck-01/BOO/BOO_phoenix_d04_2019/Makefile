##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Moi
##

SRC     =	show_string_array.c	\
			duplicate_string.c	\
			split_string.c		\
			main.c


NAME    =       show_string_array

OBJ 	= 	$(SRC:.c=.o)

LIB     =       -L./lib/phoenix -lphoenix

CFLAGS  =       -I./include

all:    		$(NAME)

$(NAME):		$(OBJ)
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

re:				fclean all