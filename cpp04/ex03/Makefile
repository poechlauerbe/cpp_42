NAME 		= PureAbstract

CXX 		= c++
CXXFLAGS 	= -std=c++98 -Wall -Werror -Wextra -MD -MP
DEBUGFLAG	= -g

OBJ_DIR		= objs

SRCS		= \
				main.cpp \
				AMateria.cpp \
				Cure.cpp \
				Ice.cpp \
				ICharacter.cpp \
				Character.cpp \
				IMateriaSource.cpp \
				MateriaSource.cpp

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
