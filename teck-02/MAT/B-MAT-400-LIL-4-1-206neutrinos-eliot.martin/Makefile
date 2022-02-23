##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile infinAdd
##

SRC				=		main.c	\
						printer.c	\
						rms.c

OBJ				=		$(SRC:.c=.o)

NAME			=		206neutrinos

ERRORFLAGS		= 		-Wall -Wextra -W

all:			$(NAME)

$(NAME):		$(OBJ)
				gcc -o $(NAME) $(OBJ) -lm $(ERRORFLAGS)

clean:
				rm -f *.o
				rm -f *~

fclean:			clean
				rm -f $(NAME)

re:				fclean all
