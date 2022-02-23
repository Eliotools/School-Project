##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Moi
##

SRC     =	main.c	\

NAME    =       generateur

OBJ 	= 	$(SRC:.c=.o)

LIB     =       -Llib/phoenix -lphoenix

LIBB     =       -Llib/my_printf -lprintf

CFLAGS  =       -Iinclude -Wall -Wextra

all:    		$(NAME)

$(NAME):		$(OBJ)
				make -C lib/phoenix
				gcc -o $(NAME) $(OBJ) $(LIB) $(CFLAGS) $(LIBB)

clean:
				make clean -C lib/phoenix
				make clean -C lib/my_printf
				rm -f *.o
				rm -f *~

fclean:
				make -C lib/phoenix fclean
				make -C lib/my_printf fclean
				make clean
				rm -f $(NAME)
				ls

re:				fclean all
