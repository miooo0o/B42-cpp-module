/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:26:21 by minakim           #+#    #+#             */
/*   Updated: 2024/09/18 21:36:07 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/// @note The parameter _name is passed as a const std::string 
/// to ensure immutability and avoid unnecessary copying, enhancing
/// both safety and performance.
Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: _name(name), _grade(grade)
{
	checkGrade();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
	:_name(src._name), _grade(src._grade)
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& src)
{
	if (this != &src)
		_grade = src.getGrade();
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
    os << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
    return (os);
}