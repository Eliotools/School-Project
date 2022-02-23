##
## EPITECH PROJECT, 2019
## CPE_BSQ_2019
## File description:
## Makefile
##

SRC	=	main.c	\
		readable.c	\
		next.c	\

LSRC	=	lib/my/my_getnbr.c		\
			lib/my/my_putchar.c	\
			lib/my/my_put_nbr.c	\
			lib/my/my_putstr.c		\
			lib/my/my_revstr.c		\
			lib/my/my_strcpy.c		\
			lib/my/my_strdup.c		\
			lib/my/my_strlen.c	\
			lib/my/my_str_is_alpha.c	\
			lib/my/wordlen.c	\
			lib/my/my_str_to_word_array.c	\
			lib/my/my_strcat.c	\
			lib/my/my_strcmp.c	\
			lib/my/my_strncmp.c

LOBJ	=	$(LSRC:.c=.o)

NAME	=	head

LIB_PATH =  ./lib/my

INCLUDE_PATH	=	./include

all:	$(NAME)

$(NAME):	$(LOBJ)
	ar rc lib/my/libmy.a $(LOBJ)
	gcc $(SRC) -o $(NAME) -L$(LIB_PATH) -lmy -I ./include -g
	rm lib/my/*.o

clean:
	rm -rf $(NAME)
	rm -rf $(LOBJ)
	cd lib/my/ && rm -rf *.o

fclean:		clean
	rm -rf $(NAME)
	rm -rf *.o

re: fclean all
