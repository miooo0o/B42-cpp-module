# Alias
CXX			= c++
VERSION		= -std=c++98
# Optional flag for MUTED mode
MUTED_FLAG ?= -DMUTED
CXXFLAGS	= -Wall -Werror -Wextra $(VERSION) $(MUTED_FLAG)
RM			= rm

# standard
NAME		=	bureaucrat
TARGET		=	./$(NAME)
OBJS_DIR	=	./obj/
SRCS_DIR	=	./src/
INCLUDE		=	-I./include -I./src
#LIBS_DIR	=	./lib/

# sources
SRCS		=	$(SRCS_DIR)main.cpp \
				$(SRCS_DIR)Bureaucrat/Bureaucrat.cpp \
				$(SRCS_DIR)AForm/AForm.cpp \
				$(SRCS_DIR)RobotomyRequestForm/RobotomyRequestForm.cpp \
				$(SRCS_DIR)PresidentialPardonForm/PresidentialPardonForm.cpp \
				$(SRCS_DIR)ShrubberyCreationForm/ShrubberyCreationForm.cpp 


OBJS		=	$(patsubst $(SRCS_DIR)%.cpp, $(OBJS_DIR)%.o, $(SRCS))

# Main Command
all: $(NAME)

$(NAME):	$(OBJS)
	@$(CXX) $(INCLUDE) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "Makefile: $(TARGET) compiled."

$(OBJS_DIR)%.o : $(SRCS_DIR)%.cpp
	@mkdir -p $(@D)
	@#echo "compiling $<"
	@$(CXX) $(INCLUDE) -c $< -o $@

clean:
	@$(RM) -rf $(OBJS_DIR)

fclean:		clean
	@$(RM) -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re