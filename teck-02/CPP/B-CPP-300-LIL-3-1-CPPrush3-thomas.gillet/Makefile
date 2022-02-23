SRC = 	testsfml.cpp \
		sfmlgraphic.cpp \
		main.cpp \
		info.cpp \
		main_ncurses.cpp \
		Box.cpp \
		ModuleGeneral.cpp \
		RAM.cpp \
		CPU.cpp \

CXX = g++
#CXXFLAGS = -W -Wall -Wextra
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lncurses

NAME = MyGKrellm

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re test
