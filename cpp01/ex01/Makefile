NAME 		= ZombieHorde

CC 			= c++
CXX 		= c++
CXXFLAGS 	= -std=c++98 -Wall -Werror -Wextra

OBJ_DIR		= objs

SRCS		= \
				main.cpp \
				Zombie.cpp \
				zombieHorde.cpp

OBJS		= $(SRCS:%.cpp=$(OBJ_DIR)/%.o)


all: 	$(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean:
	rm -rf $(OBJ_DIR)
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
