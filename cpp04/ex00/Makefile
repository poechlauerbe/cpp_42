NAME 		= Animal

CXX 		= c++
CXXFLAGS 	= -std=c++98 -Wall -Werror -Wextra -MD -MP

OBJ_DIR		= objs

SRCS		= \
				main.cpp \
				Animal.cpp \
				Dog.cpp \
				Cat.cpp \
				WrongAnimal.cpp \
				WrongCat.cpp

OBJS		= $(SRCS:%.cpp=$(OBJ_DIR)/%.o)
DEPS		 = $(SRCS:%.cpp=${OBJ_DIR}/%.d)


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

-include $(DEPS)

.PHONY: all clean fclean re
