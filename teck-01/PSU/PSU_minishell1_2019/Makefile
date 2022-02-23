##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile infinAdd
##

SRC     =       src/minishell.c	\
				src/recup_arg.c	\
				src/check_fct.c	\
				src/my_exec.c	\
				src/fct.c	\
				src/fct_str.c	\
				src/my_cd.c	\
				include/function.h

OBJ 	=		$(SRC:.c=.o) 

NAME    =       mysh

LIB     =       -L lib/my/ -l my 

CFLAGS  =       -I ./lib/my

all:    $(NAME)

$(NAME):	$(OBJ)
		make -C lib/my
		gcc -o $(NAME) $(OBJ) $(LIB) $(CFLAGS)

clean:
		make clean -C lib/my
		rm -f *.o
		rm -f *~

fclean:
		make fclean -C lib/my
		rm -f $(NAME)

re:     fclean all
