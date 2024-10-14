#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form()
    : _name("default"), _isSigned(false), _minSignGrade(1), _minExecGrade(1)
{
}

Form::Form(std::string name, const int minSignGrade, const int minExecGrade)
    : _name(name), _isSigned(false), _minSignGrade(minSignGrade), _minExecGrade(minExecGrade)
{
    if (minSignGrade < 1 || minExecGrade < 1)
        throw Form::GradeTooHighException();
    if (minSignGrade > 150 || minExecGrade > 150)
        throw Form::GradeTooLowException();
}

Form::~Form()
{
}

Form::Form(Form const &other)
    : _name(other._name), _isSigned(other._isSigned), _minSignGrade(other._minSignGrade), _minExecGrade(other._minExecGrade)
{
}

Form& Form::operator=(const Form &other)
{
    if (this != &other)
        _isSigned = other._isSigned;
    return (*this);
}
//////////////////////////////////////////////////////////////////////////////

void    Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _minSignGrade)
        throw Form::GradeTooLowException();
    _isSigned = true;
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

//////////////////////////////////////////////////////////////////////////////

std::ostream &operator<<(std::ostream &os, Form const &form)
{
    os << "Form: " << form.getName()
        << ", sign grade: " << form.getMinSignGrade() 
        << ", exec grade: " << form.getMinExecGrade();
    if (form.getIsSigned())
        os << ", signed";
    else
        os << ", not signed";
    return (os);
}