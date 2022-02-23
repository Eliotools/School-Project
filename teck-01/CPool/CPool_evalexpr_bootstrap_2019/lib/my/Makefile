##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## make
##

SRC	=	my_strtol.c 	\
		my_putchar.c	\
		my_strlen.c		\
		my_put_nbr.c	\
		my_strcpy.c 	\
		my_putstr.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mv $(NAME) ../
	cp my.h ../../include/

clean:
	rm -f $(OBJ)
	rm -f *.o
	rm -f *~

fclean: clean
	rm -f $(NAME)

re: fclean all