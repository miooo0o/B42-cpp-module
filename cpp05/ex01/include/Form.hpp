#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class Form
{
private:
	const std::string   _name;
	bool				_isSigned;
	const int			_minSignGrade;
	const int			_minExecGrade;
public:
	Form();
	Form(std::string name, const int minSignGrade, const int minExecGrade);
	~Form();
	Form(Form const &other);
	Form& operator=(const Form &other);
	
	void		beSigned(Bureaucrat &bureaucrat);
	
	int			getMinSignGrade() const;
	int 		getMinExecGrade() const;
	std::string	getName() const;
	bool		getIsSigned() const;

	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, Form const &form);
