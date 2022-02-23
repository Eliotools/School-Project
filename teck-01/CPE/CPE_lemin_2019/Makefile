##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## makefile
##

DIR	=	src/

SRC	=	$(DIR)graph.c	\
		$(DIR)get_all_info.c	\
		$(DIR)get_info_two.c	\
		$(DIR)string_to_double_tab.c	\
		$(DIR)output.c	\
		$(DIR)basics.c	\
		$(DIR)main.c	\
		$(DIR)space_x.c	\
		$(DIR)len.c	\
		$(DIR)error_handle.c	\
		$(DIR)graph_and_se.c	\
		$(DIR)check_index.c	\
		$(DIR)print_moves.c	\


OBJ	=	$(SRC:.c=.o)

NAME	=	lem_in

CFLAGS	=	-Wall -Wextra -I ./include -g

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
