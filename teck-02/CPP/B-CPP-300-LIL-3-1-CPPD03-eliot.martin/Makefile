##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Moi
##

SRC     =	file_1.c	\
			file_2.c	\
			file_3.c	\
			file_4.c	\

NAME    =	libstring.a

OBJ 	= 	$(SRC:.c=.o)

all:    		$(NAME)

$(NAME):		$(OBJ)
				ar rc $(NAME) $(OBJ)

clean:
				rm -rf $(OBJ)
fclean:
				rm -f $(NAME)

re:				fclean all