# Alias
CXX			= c++
VERSION		= -std=c++98
CXXFLAGS	= -Wall -Werror -Wextra $(VERSION)
RM			= rm

# standard
NAME		=	except_replace
OBJS_DIR	=	./obj/
SRCS_DIR	=	./src/
INCLUDE		=	-I./include
#LIBS_DIR	=	./lib/

# sources
SRCS		=	$(SRCS_DIR)main.cpp

OBJS		=	$(patsubst $(SRCS_DIR)%.cpp, $(OBJS_DIR)%.o, $(SRCS))

# Main Command
all: $(NAME)

$(NAME):	$(OBJS)
	@$(CXX) $(INCLUDE) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.cpp
	@mkdir -p $(@D)
	@echo "Compiling $<"
	@$(CXX) $(INCLUDE) -c $< -o $@

clean:
	@$(RM) -rf $(OBJS_DIR)

fclean:		clean
	@$(RM) -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
