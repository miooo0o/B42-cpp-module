cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98")

macro(set_project_name NAME)
    set(PROJECT_NAME ${NAME})
    project(${PROJECT_NAME})
endmacro()

project(btc)

# Add all your source files
set(SOURCES
        src/main.cpp
        src/class/Date.cpp
        src/class/BitcoinExchange.cpp
)

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# link target directories
target_include_directories(${PROJECT_NAME} PRIVATE src include)