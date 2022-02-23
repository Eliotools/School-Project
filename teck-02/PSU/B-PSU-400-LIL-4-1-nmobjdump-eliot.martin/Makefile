##
## EPITECH PROJECT, 2021
## B-PSU-400-LIL-4-1-nmobjdump-eliot.martin [WSL: Ubuntu]
## File description:
## Makefile
##

SRC  =   			my_nm.c \

SRC_OBJDUMP =   	my_objdump.c	\

OBJ  =   			$(SRC:.c=.o)
OBJ_OBJDUMP = 		$(SRC_OBJDUMP:.c=.o)

NAME =   			my_nm
NAME_OBJDUMP =  	my_objdump

nm: 				$(NAME)
objdump:			$(NAME_OBJDUMP)

$(NAME): 			$(OBJ)
					gcc -o $(NAME) $(OBJ)

$(NAME_OBJDUMP):	$(OBJ_OBJDUMP)
					gcc -o $(NAME_OBJDUMP) $(OBJ_OBJDUMP)

all: 				objdump nm

clean:
					rm -f $(OBJ)
					rm -f $(OBJ_OBJDUMP)

fclean: 			clean
					rm -f $(NAME)
					rm -f $(NAME_OBJDUMP)

re: fclean all