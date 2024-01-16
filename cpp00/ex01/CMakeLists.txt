cmake_minimum_required(VERSION 3.12)

project(PhoneBook)

# Add all your source files
set(SOURCES
		src/main.cpp
		src/Contact/Contact.cpp
		src/PhoneBook/PhoneBook.cpp
		)

# Create the executable
add_executable(phonebook ${SOURCES})

target_include_directories(phonebook PRIVATE src)

target_include_directories(phonebook PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/src/PhoneBook
		${CMAKE_CURRENT_SOURCE_DIR}/src/Contact
        )