##
## EPITECH PROJECT, 2021
## B-OOP-400-LIL-4-1-tekspice-thomas.gillet [WSL: Ubuntu]
## File description:
## Makefile
##

SRC	=	Chipset.cpp	\
		main.cpp	\
		And_4081.cpp\
		Or_4071.cpp	\
		Error.cpp	\
		Parser.cpp


OBJ	=	$(SRC:.c=.o)

NAME=	nanotekspice

ERRORFLAGS	= -Wall -Wextra -W

all:	$(NAME)

$(NAME):    
			g++ -o $(NAME) $(OBJ) $(ERRORFLAGS)

clean:
			rm -f *.o
			rm -f *~
 
fclean:
			rm -f $(NAME)
 
re:
			make fclean
			make all
