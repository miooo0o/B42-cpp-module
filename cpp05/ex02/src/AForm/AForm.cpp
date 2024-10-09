#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm()
    : _name("default"), _isSigned(false), _minSignGrade(1), _minExecGrade(1)
{
}

AForm::AForm(std::string name, const int minSignGrade, const int minExecGrade)
    : _name(name), _isSigned(false), _minSignGrade(minSignGrade), _minExecGrade(minExecGrade)
{
    if (minSignGrade < 1 || minExecGrade < 1)
        throw AForm::GradeTooHighException();
    if (minSignGrade > 150 || minExecGrade > 150)
        throw AForm::GradeTooLowException();
}

AForm::~AForm()
{
}

AForm::AForm(AForm const &other)
    : _name(other._name), _isSigned(other._isSigned), _minSignGrade(other._minSignGrade), _minExecGrade(other._minExecGrade)
{
}

AForm& AForm::operator=(const AForm &other)
{
    if (this != &other)
        _isSigned = other._isSigned;
    return (*this);
}
//////////////////////////////////////////////////////////////////////////////

void    AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _minSignGrade)
        throw AForm::GradeTooLowException();
    _isSigned = true;
}

//////////////////////////////////////////////////////////////////////////////

int     AForm::getMinSignGrade() const
{
    return (_minSignGrade);
}

int     AForm::getMinExecGrade() const
{
    return (_minExecGrade);
}

std::string AForm::getName() const
{
    return (_name);
}

bool    AForm::getIsSigned() const
{
    return (_isSigned);
}

//////////////////////////////////////////////////////////////////////////////

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("grade too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("grade too low");
}

//////////////////////////////////////////////////////////////////////////////

std::ostream &operator<<(std::ostream &os, AForm const &form)
{
    os << "AForm: " << form.getName()
        << ", sign grade: " << form.getMinSignGrade() 
        << ", exec grade: " << form.getMinExecGrade();
    if (form.getIsSigned())
        os << ", signed";
    else
        os << ", not signed";
    return (os);
}