##
## EPITECH PROJECT, 2019
## makefiles
## File description:
## make
##


SRC		=	main.c 		\

OBJ		=	$(SRC:.c=.o)

NAME		=	bsq

CFLAGS		=	 -L./lib/my -lmy -I./include -g

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my
		gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		make -C lib/my clean
		rm -f *.o
		rm -f *~

fclean: clean
		make -C lib/my fclean
		rm -f $(NAME)

re:		fclean all
