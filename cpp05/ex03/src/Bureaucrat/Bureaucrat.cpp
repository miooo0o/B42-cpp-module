/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:26:21 by minakim           #+#    #+#             */
/*   Updated: 2024/10/14 18:23:44 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

/// @note The parameter _name is passed as a const std::string 
/// to ensure immutability and avoid unnecessary copying, enhancing
/// both safety and performance.
Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: _name(name), _grade(grade)
{
	#ifndef MUTED
        std::cout << "Bureaucrat, name: " << _name << ", grade: " << _grade << std::endl;
    #endif
	checkGrade();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
	:_name(src._name), _grade(src._grade)
{
	#ifndef MUTED
        std::cout << "Bureaucrat, " << _name << " copy constructed." << std::endl;
    #endif
}

Bureaucrat::~Bureaucrat()
{
	#ifndef MUTED
        std::cout << "Bureaucrat, " << _name << " dismissed." << std::endl;
    #endif
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& src)
{
	if (this != &src)
		_grade = src.getGrade();
	#ifndef MUTED
        std::cout << "Bureaucrat, " << _name << " copy assigned." << std::endl;
    #endif
	return (*this);
}

//////////////////////////////////////////////////////////////////////////////

void	Bureaucrat::checkGrade()
{
	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
}

void	Bureaucrat::signForm(Form& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed the form \"" << form.getName() << "\"." << std::endl;
    }
    catch(const std::exception& e)
    {
		std::cerr << _name << " couldn't sign the form \"" << form.getName() << "\" because " << e.what() << std::endl;

    }
}


void Bureaucrat::executeForm(const Form &form)
{
	try
	{
		form.execute(*this);
    	std::cout << _name << " executed the form \"" << form.getName() << "\"." << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << _name << " couldn't execute the form \"" << form.getName() << "\" because " << e.what() << std::endl;
    }
}

//////////////////////////////////////////////////////////////////////////////

std::string	Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

//////////////////////////////////////////////////////////////////////////////

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("grade too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("grade too low");

}

//////////////////////////////////////////////////////////////////////////////

std::ostream& operator<<(std::ostream& os, const Bureaucrat& src)
{
    os << src.getName() << "'s grade " << src.getGrade() << ".";
    return (os);
}