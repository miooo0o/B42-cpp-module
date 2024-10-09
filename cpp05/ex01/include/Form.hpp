#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class AForm
{
private:
	const std::string   _name;
	bool				_isSigned;
	const int			_minSignGrade;
	const int			_minExecGrade;
public:
	AForm();
	AForm(std::string name, const int minSignGrade, const int minExecGrade);
	~AForm();
	AForm(AForm const &other);
	AForm& operator=(const AForm &other);
	
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

std::ostream &operator<<(std::ostream &out, AForm const &form);