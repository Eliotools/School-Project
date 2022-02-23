##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile assistance
##

LDFLAGS	=	-luuid -L `pwd`/libs/myteams/ -lmyteams -Wl,-rpath=$(PWD)/libs/myteams

SRC_SERV	=	server/server.c	\
				server/get.c	\
				server/get_2.c	\
				server/add_to_file.c	\
				server/create.c	\
				server/command.c	\
				server/command_2.c	\
				server/log.c	\
				server/team.c	\
				server/team_bis.c	\
				server/send.c	\
				server/setup_struct.c	\
				server/use.c	\
				server/create_file.c	\
				server/user.c	\
				server/list.c	\
				server/list_bis.c	\
				server/info.c	\
				server/subscrib.c	\
				server/unsubscribe.c	\
				server/messsage_serv.c	\
				server/help.c	\
				lib/get_word.c	\
				lib/uuid_name.c	\
				lib/str_to_word_array.c	\
				lib/file.c	\

SRC_CLI		=	client/client.c	\
				client/client_2.c	\
				client/client_3.c	\
				client/main_client.c	\
				client/messages.c	\
				client/check_file.c	\
				client/parse_user_infos.c	\
				lib/get_word.c	\
				lib/uuid_name.c	\
				lib/str_to_word_array.c	\
				lib/file.c	\

OBJ_SERV	=	$(SRC_SERV:.c=.o)

OBJ_CLI		=	$(SRC_CLI:.c=.o)

NAME_SERV	=	myteams_server

NAME_CLI	=	myteams_cli

CFLAGS	=	-Wall -Wextra -I ./include

all:	$(NAME_SERV) $(NAME_CLI)

$(NAME_SERV):	$(OBJ_SERV)
	gcc -o $(NAME_SERV) $(OBJ_SERV) $(LDFLAGS)

$(NAME_CLI):	$(OBJ_CLI)
	gcc -o $(NAME_CLI) $(OBJ_CLI) $(LDFLAGS)

clean:
	$(RM) $(OBJ_SERV)
	$(RM) $(OBJ_CLI)

fclean: clean
	$(RM) $(NAME_SERV)
	$(RM) $(NAME_CLI)

re:	fclean all
