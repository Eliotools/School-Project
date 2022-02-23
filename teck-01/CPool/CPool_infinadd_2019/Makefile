##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## make
## 

SRC			=	test.c

OBJ			=	$(SRC:.c=.o) 

NAME			=	test

CFLAGS			=	 -L./lib -lmy -I./include

all:			$(NAME)

$(NAME):		$(OBJ)
			make -C lib/my
			gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
			make -C lib/my clean
			rm -f *.o
			rm -f *~

fclean: 		clean
			make -C lib/my fclean
			rm -f $(NAME)

re:			fclean all
