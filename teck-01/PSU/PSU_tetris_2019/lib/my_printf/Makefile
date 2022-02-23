##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Moi
##
SRC	=	flag_a.c	\
		flag_b.c	\
		convert.c	\
		my_itob.c 	\
		my_next.c	\
		../phoenix/reverse_string.c \
		../phoenix/show_number.c 	\
		../phoenix/len.c	\
		../phoenix/show_string.c	\
		../phoenix/my_putchar.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libprintf.a

MY_H	=	printf.h

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp printf.h ../../include/printf.h

clean:
	rm -f $(OBJ)
	rm -f $(NAME)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
