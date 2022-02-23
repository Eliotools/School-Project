##
## EPITECH PROJECT, 2019
## Makefile D10
## File description:
## Makefile for lib
##

SRC 	=	my_convert_octal.c	\
			my_hexa_or_bin_convert.c	\
			my_isneg.c	\
			my_printf.c	\
			my_putchar.c	\
			my_putnbr.c	\
			my_putstr_error.c	\
			my_putstr.c	\
			my_revstr.c	\
			my_unsigned_putnbr.c	\

OBJ 	=	$(SRC:.c=.o)

NAME	=	test

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc libmy.a $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: 	fclean all

auteur:
	echo $(USER) > auteur
