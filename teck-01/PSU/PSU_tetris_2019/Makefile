##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Moi
##

SRC     =	main.c	\
			make_tetrimonos.c	\
			make_struc.c	\
			touch.c	\
			space.c	\
			debug.c	\
			maker.c	\

NAME    =       tetris

OBJ 	= 	$(SRC:.c=.o)

LIB     =       -Llib/phoenix -lphoenix

LIBB     =       -Llib/my_printf -lprintf

CFLAGS  =       -Iinclude -Wall -Wextra

NFLAGS  =		-lncurses

all:    		$(NAME)

$(NAME):		$(OBJ)
				make -C lib/phoenix
				gcc -o $(NAME) $(OBJ) $(LIB) $(CFLAGS) $(LIBB) $(NFLAGS)

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
