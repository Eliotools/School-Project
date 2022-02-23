##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## make
## 
NAME    =       grep

SRC     =       grep.c

OBJ     =       $(SRC:.c=.o)

LIB     =       -L../lib/my/ -lmy

all:	$(NAME)

$(NAME):		$(OBJ)
				gcc -o $(NAME) $(OBJ) $(LIB)

clean:
		rm -f *.o
		rm -f *~

fclean: clean
		rm -f $(NAME)

re:		fclean  all