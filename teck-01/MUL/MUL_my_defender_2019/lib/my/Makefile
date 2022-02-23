##
## EPITECH PROJECT, 2019
## CPool_Day10_2019
## File description:
## Makefile
##

SRC	=		my_put_nbr.c			\
			my_putchar.c			\
			my_putstr.c			\
			my_strlen.c			\
			my_put_nbr_octa.c		\
			my_put_nbr_hexa.c		\
			my_put_nbr_u.c			\
			my_put_nbr_bin.c		\
			first_flags.c			\
			second_flags.c			\
			third_flags.c			\
			my_printf.c			

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS	=	-I include

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm *.o
	rm -f *~

fclean:	clean
	rm -f $(NAME)

re:		fclean all
