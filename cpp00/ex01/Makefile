# Alias
CXX			= c++
VERSION		= -std=c++98
CXXFLAGS	= -Wall -Werror -Wextra $(VERSION)
RM			= rm

# standard
NAME		=	phonebook
OBJS_DIR	=	./obj/
SRCS_DIR	=	./src/
#INCLUDE		=	-I ./src/
#LIBS_DIR	=	./lib/

# sources
SRCS		=	src/main.cpp src/Contact/Contact.cpp src/PhoneBook/PhoneBook.cpp
OBJS        = $(addprefix $(OBJS_DIR), $(notdir $(SRCS:.cpp=.o)))


# Main Command
all: $(NAME)

$(NAME):	$(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.cpp
	@mkdir -p $(@D)
	@$(CXX) -c $< -o $@

clean:
	@$(RM) -rf $(OBJS_DIR)

fclean:		clean
	@$(RM) -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

dev:
			@$(CXX) -g -o $(NAME) $(SRCS) $^
			@#$(CXX) -g -o $(NAME) $(SRCS) $^ $(INCLUDE)
