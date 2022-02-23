##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile infinAdd
##

SRC				=		server.c \
						log.c \
						all_cmd.c \
						struct_setup.c \
						cmb.c

OBJ				=		$(SRC:.c=.o)

NAME			=		myftp

ERRORFLAGS		= 		-Wall -Wextra -W

all:			$(NAME)

$(NAME):		$(OBJ)
				gcc -o $(NAME) $(OBJ) $(ERRORFLAGS)

server:			$(OBJ)
				gcc -o $(NAME) $(OBJ) $(ERRORFLAGS)

clean:
				rm -f *.o
				rm -f *~

fclean:			clean
				rm -f $(NAME)

re:				fclean all
