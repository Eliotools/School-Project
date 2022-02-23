##
## EPITECH PROJECT, 2019
## makefile
## File description:
## runner
##

SRC		=	main.c		\

OBJ		=	$(SRC:.c=.o)

NAME		=	my_defender

CFLAGS		=	-l csfml-graphics -l csfml-audio -l csfml-system -l csfml-window

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my
		gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		rm -f $(OBJ)
		rm *~

fclean:		clean
		rm -f $(NAME)

re:		fclean all
