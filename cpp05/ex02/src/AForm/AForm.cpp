/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:20:35 by minakim           #+#    #+#             */
/*   Updated: 2024/10/14 18:22:01 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Form::Form()
    : _name("default"), _isSigned(false), _minSignGrade(1), _minExecGrade(1)
{
    #ifndef MUTED
        std::cout << "Form \"" << getName() << "\" created." << std::endl;
    #endif
}

Form::Form(std::string name, const int minSignGrade, const int minExecGrade)
    : _name(name), _isSigned(false), _minSignGrade(minSignGrade), _minExecGrade(minExecGrade)
{
    #ifndef MUTED
        std::cout << "Form \"" << getName() << "\" created." << std::endl;
    #endif
    if (minSignGrade < 1 || minExecGrade < 1)
        throw Form::GradeTooHighException();
    if (minSignGrade > 150 || minExecGrade > 150)
        throw Form::GradeTooLowException();
}

Form::~Form()
{
    #ifndef MUTED
        std::cout << "Form \"" << getName() << "\" dismissed." << std::endl;
    #endif
}

Form::Form(Form const &other)
    : _name(other._name), _isSigned(other._isSigned), 
    _minSignGrade(other._minSignGrade), _minExecGrade(other._minExecGrade)
{
    #ifndef MUTED
        std::cout << "Form \"" << getName() << "\" copy constructed." << std::endl;
    #endif
}

Form& Form::operator=(const Form &other)
{
    if (this != &other)
        _isSigned = other._isSigned;
    
    #ifndef MUTED
         std::cout << "Form \"" << getName() << "\" copy constructed." << std::endl;
    #endif
    return (*this);
}
//////////////////////////////////////////////////////////////////////////////

void    Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _minSignGrade)
        throw Form::GradeTooLowException();
    _isSigned = true;
}


void    Form::execute(Bureaucrat const &executor) const
{
    if (!getIsSigned())
        throw Form::FormNotSignedException();
    if (executor.getGrade() > _minExecGrade)
        throw Form::GradeTooLowException();
    if (executor.getGrade() < 1)
        throw Form::GradeTooHighException();
    else
        beExecute(executor);
}

//////////////////////////////////////////////////////////////////////////////

int     Form::getMinSignGrade() const
{
    return (_minSignGrade);
}

int     Form::getMinExecGrade() const
{
    return (_minExecGrade);
}

std::string Form::getName() const
{
    return (_name);
}

bool    Form::getIsSigned() const
{
    return (_isSigned);
}

//////////////////////////////////////////////////////////////////////////////

const char* Form::GradeTooHighException::what() const throw()
{
    return ("grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("grade too low");
}

const char* Form::FormNotSignedException::what() const throw()
{
    return ("Form is not signed");
}
//////////////////////////////////////////////////////////////////////////////

std::ostream &operator<<(std::ostream &os, Form const &form)
{
    os << "Form: \"" << form.getName() << "\""
        << ", sign grade: " << form.getMinSignGrade() 
        << ", exec grade: " << form.getMinExecGrade();
    if (form.getIsSigned())
        os << ", signed";
    else
        os << ", not signed";
    return (os);
    return (os);
}