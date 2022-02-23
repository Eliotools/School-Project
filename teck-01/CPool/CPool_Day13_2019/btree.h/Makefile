##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## make
## 
NAME    =       cat

SRC     =       cat.c

OBJ     =       $(SRC:.c=.o)

LIB     =       -L../lib/my/ -lmy

all:	$(NAME)

$(NAME):		$(OBJ)
		make -C ../lib/my/
		gcc -o $(NAME) $(OBJ) $(LIB)

clean:
		rm -f *.o
		rm -f *~

fclean: clean
		rm -f $(NAME)

re:		fclean  all