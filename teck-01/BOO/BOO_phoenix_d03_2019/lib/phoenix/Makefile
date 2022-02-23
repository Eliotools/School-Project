##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Moi
##
SRC	=	my_putchar.c 	\
		len.c 	\
		is_prime_number.c	\
		iterative_factorial.c 	\
		my_strcapitalize.c 	\
		my_strcpy.c 	\
		my_strncmp.c 	\
		my_strstr.c 	\
		my_strupcase.c 	\
		recursive_power.c 	\
		reverse_string.c 	\
		show_alphabet.c	\
		show_number.c 	\
		show_combinations.c 	\
		show_string.c 	\
		to_number.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libphoenix.a

MY_H	=	phoenix.h

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp phoenix.h ../../include/phoenix.h

clean:
	rm -f $(OBJ)
	rm -f $(NAME)

fclean:
	make clean
	rm -f $(NAME)

re:
	fclean all
