##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Moi
##
SRC	=	my_putchar.c    \
		len.c   \
		str_array.c	\
		my_strcpy.c     \
		reverse_string.c        \
		show_string_array.c     \
		show_number.c   \
		show_string.c   \
		to_number.c	\
		str_to_word_array.c	\
		readable.c	\
		my_strcmp.c	\
		my_strcat.c	\
		chartochar.c	\
		randomizer.c	\

OBJ     =       $(SRC:.c=.o)

NAME    =       libphoenix.a

MY_H    =       phoenix.h

all:    $(NAME)

$(NAME):        $(OBJ)
		make -C ../my_printf
		ar rc $(NAME) $(OBJ)
		cp phoenix.h ../../include/phoenix.h

clean:
		rm -f $(OBJ)
		rm -f $(NAME)

fclean: 	clean
		rm -f $(NAME)

re:     	fclean all
