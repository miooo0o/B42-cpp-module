
### Makefile
<details>
	<summary>Basic Makefile Template for CPP Projects</summary>

```Makefile 
# Alias
CXX		=	c++
VERSION		=	-std=c++98
CXXFLAGS	=	-Wall -Werror -Wextra $(VERSION)
RM		=	rm
	
# standard
NAME		=	megaphone
OBJS_DIR	=	./obj/
SRCS_DIR	=	./
#INCLUDE	=	-I ./src/
#LIBS_DIR	=	./lib/
		
# sources
SRCS		=	megaphone.cpp
OBJS		=	$(SRCS:$(SRCS_DIR)%.cpp=$(OBJS_DIR)%.o)


# Main Command
all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(@D)
	@$(CXX) -c $< -o $@

clean:
	@$(RM) -rf $(OBJS_DIR)

fclean:		clean
	@$(RM) -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re

dev:
	@$(CXX) -g -o $(NAME) $(SRCS) $^
#	@$(CXX) -g -o $(NAME) $(SRCS) $^ $(INCLUDE)
```

</details>