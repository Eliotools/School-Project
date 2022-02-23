SRC	=	my_getnbr.c \
		my_revstr.c \
		my_putchar.c \
		my_putstr.c \
		my_put_nbr.c \
		my_strlen.c 	\
		my_sort_int_array.c \
		my_strlen.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

MY_H	=	my.h

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp my.h ../../include/my.h

clean:
	rm -f $(OBJ)
	rm -f $(NAME)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
