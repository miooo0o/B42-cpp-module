cmake_minimum_required(VERSION 3.12)

macro(set_project_name NAME)
	set(PROJECT_NAME ${NAME})
	project(${PROJECT_NAME})
endmacro()

project(BrainzzZ)

# Add all your source files
set(SOURCES
		src/main.cpp
		src/Zombie/Zombie.cpp
		src/Zombie/Zombie.h
		src/Zombie/randomChump.cpp
		src/Zombie/newZombie.cpp
		../ex01/src/main.cpp
		../ex01/src/Zombie/Zombie.cpp
		../ex01/src/zombieHorde.cpp
		../ex02/src/main.cpp
)

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# link target directories
target_include_directories(${PROJECT_NAME} PRIVATE src)