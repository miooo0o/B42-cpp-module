cmake_minimum_required(VERSION 3.12)

macro(set_project_name NAME)
	set(PROJECT_NAME ${NAME})
	project(${PROJECT_NAME})
endmacro()

project(except_replace)

# Add all your source files
set(SOURCES
		src/main.cpp
		src/Replace/Replace.h
		src/Replace/Replace.cpp
)

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# link target directories
target_include_directories(${PROJECT_NAME} PRIVATE src include)