#pragma once

#include <map>
#include <exception>

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Form;

class Intern
{
public:
	Intern();
	~Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);

	Form*   makeForm(const std::string& formName, const std::string& target);

	class FormNotFoundException : public std::exception
	{
		virtual const char* what() const throw();
	};

private:
	typedef Form* (*FormCreator)(std::string target);

	static Form* makeShrubbery(std::string target);
	static Form* makeRobotomy(std::string target);
	static Form* makePresidential(std::string target);
};