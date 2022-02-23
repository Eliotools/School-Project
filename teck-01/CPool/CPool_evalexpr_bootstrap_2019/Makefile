##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## make
## 

SRC			=	eval_expr.c 	\
				test.c			\
				calculatron.c	\
				my_parsing.c 	\
				my_find_p.c 	\
				

OBJ			=	$(SRC:.c=.o) 

NAME		=	eval_expr

CFLAGS		=	 -L./lib -lmy -I./include -g

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my 	
		gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		make -C lib/my clean
		rm -f *.o
		rm -f *~

fclean: clean
		make -C lib/my fclean
		rm -f $(NAME)

re:		fclean all
