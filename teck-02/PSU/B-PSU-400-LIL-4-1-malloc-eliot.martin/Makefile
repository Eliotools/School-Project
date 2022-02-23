##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile infinAdd
##

SRC     =       my_malloc.c

OBJ 	=		$(SRC:.c=.o) 

NAME    =       libmy_malloc.so

all:    $(NAME)

$(NAME):	
			gcc -c -fPIC $(SRC)
			gcc -shared -o $(NAME) $(OBJ)

clean:
			rm -f *.o
			rm -f *~

fclean:
			rm -f $(NAME)

re:     	fclean all
