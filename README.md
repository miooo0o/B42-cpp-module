
### Makefile
<details>
	<summary>Basic Makefile Template for CPP Projects</summary>

```Makefile 
# Alias
CXX			= c++
VERSION		= -std=c++98
CXXFLAGS	= -Wall -Werror -Wextra $(VERSION)
RM			= rm

# standard
NAME		=	name
TARGET		=	./$(NAME)
OBJS_DIR	=	./obj/
SRCS_DIR	=	./src/
INCLUDE		=	-I./include -I.$(SRCS_DIR)Raplace
#LIBS_DIR	=	./lib/

# sources
SRCS		=	$(SRCS_DIR)main.cpp

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

```

</details>


### cmake
<details>
	<summary>Basic cmake Template for CPP Projects</summary>

```cmake
#cmake_minimum_required(VERSION 3.12)

macro(set_project_name NAME)
	set(PROJECT_NAME ${NAME})
	project(${PROJECT_NAME})
endmacro()

project(name)

# Add all your source files
set(SOURCES
		src/main.cpp
)

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# link target directories
target_include_directories(${PROJECT_NAME} PRIVATE src include)
```

</details>