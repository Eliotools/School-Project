##
## EPITECH PROJECT, 2021
## ARCADE
## File description:
## Makefile
##

BLACK        := $(shell tput -Txterm setaf 0)
RED          := $(shell tput -Txterm setaf 1)
GREEN        := $(shell tput -Txterm setaf 2)
YELLOW       := $(shell tput -Txterm setaf 3)
LIGHTPURPLE  := $(shell tput -Txterm setaf 4)
PURPLE       := $(shell tput -Txterm setaf 5)
BLUE         := $(shell tput -Txterm setaf 6)
WHITE        := $(shell tput -Txterm setaf 7)
RESET := $(shell tput -Txterm sgr0)

SRC_SFML	=	graphic/sfml/sfmldraw.cpp

SRC_SDL2	= 	graphic/sdl_deux/MySDL2.cpp

SRC_NCURSES	=	graphic/ncurses/ncurses.cpp

SRC_NIBBLER	=	game/nibbler/nibbler.cpp

SRC_CENTIPEDE	=	game/centipede/centipede.cpp

SRC_CORE	=	core_f/core.cpp	\
				core_f/DLLoader.cpp	\
				core_f/libfinder.cpp	\
				core_f/main.cpp	

OBJ_SFML	=	$(SRC_SFML:.cpp=.o)
OBJ_SDL2	=	$(SRC_SDL2:.cpp=.o)
OBJ_NCURSES	=	$(SRC_NCURSES:.cpp=.o)
OBJ_CENTIPEDE	=	$(SRC_CENTIPEDE:.cpp=.o)
OBJ_NIBBLER	=	$(SRC_NIBBLER:.cpp=.o)
OBJ_CORE	=	$(SRC_CORE:.cpp=.o)

NAME	=	arcade

SFML	=	sfml
SDL	=	sdl2
NCURSES	=	ncurses
NIBBLER	=	nibbler
CENTIPEDE	=	centipede

ERRORFLAGS	= 	-Wall -Wextra -W

FLAGS_SFML 	=	-lsfml-graphics -lsfml-system -lsfml-window

FLAGS_NCURSES	=	-lncurses

FLAGS_SDL = -lSDL2

all: $(NAME)

$(NAME):	graphicals games core

## GRAPHIC

sfml:
		@echo "\t${YELLOW}[GRAPHICS] Building SFML lib${RESET}"
		g++ -c -fPIC $(SRC_SFML) $(FLAGS_SFML)
		@mv *.o graphic/sfml/
		g++ -shared -o $(NAME)_$(SFML).so $(OBJ_SFML) $(FLAGS_SFML)
		@mv $(NAME)_$(SFML).so lib/
		@echo "\t${GREEN}[GRAPHICS] Build SFML lib${RESET}"

ncurses:
		@echo "\t${YELLOW}[GRAPHICS] Building NCURSES lib${RESET}"
		g++ -c -fPIC $(SRC_NCURSES) $(FLAGS_NCURSES)
		@mv *.o graphic/ncurses/
		g++ -shared -o $(NAME)_$(NCURSES).so $(OBJ_NCURSES) $(FLAGS_NCURSES)
		@mv $(NAME)_$(NCURSES).so lib/
		@echo "\t${GREEN}[GRAPHICS] Build NCURSES lib${RESET}"


sdl:
		@echo "\t${YELLOW}[GRAPHICS] Building SDL2 lib${RESET}"
		g++ -c -fPIC $(SRC_SDL2) $(FLAGS_SDL)
		@mv *.o graphic/sdl_deux/
		g++ -shared -o $(NAME)_$(SDL).so $(OBJ_SDL2) $(FLAGS_SDL)
		@mv $(NAME)_$(SDL).so lib/
		@echo "\t${GREEN}[GRAPHICS] Build SDL2 lib${RESET}"

## GAME
centipede:
		@echo "\t${BLUE}[GAME] Building Centipede lib${RESET}"
		g++ -c -fPIC $(SRC_CENTIPEDE)
		@mv *.o game/centipede/
		g++ -shared -o $(NAME)_$(CENTIPEDE).so $(OBJ_CENTIPEDE)
		@mv $(NAME)_$(CENTIPEDE).so lib/
		@echo "\t${PURPLE}[GAME] Build Centipede lib${RESET}"


nibbler:
		@echo "\t${BLUE}[GAME] Building Nibbler lib${RESET}"
		g++ -c -fPIC $(SRC_NIBBLER)
		@mv *.o game/nibbler/
		g++ -shared -o $(NAME)_$(NIBBLER).so $(OBJ_NIBBLER)
		@mv $(NAME)_$(NIBBLER).so lib/
		@echo "\t${PURPLE}[GAME] Build Nibbler lib${RESET}"


graphicals:	 sfml  ncurses sdl

games:	centipede  nibbler 

core:	
	@echo "\t${GREEN}[ARCADE] Building Core${RESET}"
	g++ -o $(NAME) $(SRC_CORE) -ldl 
	@echo "\t${GREEN}[ARCADE] Build Core${RESET}"

clean_graphics:
		$(RM) $(OBJ_SFML)
		$(RM) $(OBJ_SDL2)
		$(RM) $(OBJ_NCURSES)

clean_games:
		$(RM) $(OBJ_NIBBLER)
		$(RM) $(OBJ_CENTIPEDE)

clean:	clean_graphics clean_games clean_lib

fclean:	clean
		$(RM) $(NAME)

clean_lib:
		$(RM) lib/*.so

re:	fclean all
