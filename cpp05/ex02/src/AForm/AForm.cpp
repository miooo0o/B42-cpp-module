#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm()
    : _name("default"), _isSigned(false), _minSignGrade(1), _minExecGrade(1)
{
    #ifndef MUTED
        std::cout << "AForm \"" << getName() << "\" created." << std::endl;
        std::cout << "Grades: sign 1, exec 1 (default)" << std::endl;
    #endif
}

AForm::AForm(std::string name, const int minSignGrade, const int minExecGrade)
    : _name(name), _isSigned(false), _minSignGrade(minSignGrade), _minExecGrade(minExecGrade)
{
    #ifndef MUTED
        std::cout << "AForm \"" << getName() << "\" created." << std::endl;
        std::cout << "Grades: sign " << _minSignGrade << ", exec " << _minExecGrade << std::endl;
    #endif
    if (minSignGrade < 1 || minExecGrade < 1)
        throw AForm::GradeTooHighException();
    if (minSignGrade > 150 || minExecGrade > 150)
        throw AForm::GradeTooLowException();
}

AForm::~AForm()
{
    #ifndef MUTED
        std::cout << "AForm \"" << getName() << "\" dismissed." << std::endl;
    #endif
}

AForm::AForm(AForm const &other)
    : _name(other._name), _isSigned(other._isSigned), 
    _minSignGrade(other._minSignGrade), _minExecGrade(other._minExecGrade)
{
    #ifndef MUTED
        std::cout << "AForm \"" << getName() << "\" copy constructed." << std::endl;
    #endif
}

AForm& AForm::operator=(const AForm &other)
{
    if (this != &other)
        _isSigned = other._isSigned;
    
    #ifndef MUTED
         std::cout << "AForm \"" << getName() << "\" copy constructed." << std::endl;
    #endif
    return (*this);
}
//////////////////////////////////////////////////////////////////////////////

void    AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _minSignGrade)
        throw AForm::GradeTooLowException();
    _isSigned = true;
}


void    AForm::execute(Bureaucrat const &executor) const
{
    if (!getIsSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > _minExecGrade)
        throw AForm::GradeTooHighException();
    else
        beExecute(executor);
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

const char* AForm::FormNotSignedException::what() const throw()
{
    return ("Form is not signed");
}
//////////////////////////////////////////////////////////////////////////////

std::ostream &operator<<(std::ostream &os, AForm const &form)
{
    os << "AForm: \"" << form.getName() << "\""
        << ", sign grade: " << form.getMinSignGrade() 
        << ", exec grade: " << form.getMinExecGrade();
    if (form.getIsSigned())
        os << ", signed";
    else
        os << ", not signed";
    return (os);
    return (os);
}