#include "PresidentialPardonForm.hpp"

////////////////////////////////////////////////////////////////////////////////
// constructor & destructor
////////////////////////////////////////////////////////////////////////////////

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("Presidential Pardon Form", 25, 5)
{
    #ifndef MUTED
        std::cout << "PresidentialPardonForm created." << std::endl;
        std::cout << "Grades: sign 25, exec 5" << std::endl;
    #endif
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("Presidential Pardon Form", 25, 5), _target(target)
{
    #ifndef MUTED
        std::cout << "PresidentialPardonForm created for " << _target << "." << std::endl;
        std::cout << "Grades: sign 25, exec 5" << std::endl;
    #endif
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    #ifndef MUTED
        std::cout << "PresidentialPardonForm for " << _target << " dismissed." << std::endl;
    #endif   
}

////////////////////////////////////////////////////////////////////////////////
// copy constructor & assignation operator
////////////////////////////////////////////////////////////////////////////////

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other), _target(other._target)
{
    #ifndef MUTED
        std::cout << "PresidentialPardonForm for " << _target << " copy constructed." << std::endl;
    #endif
}

PresidentialPardonForm&
    PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    #ifndef MUTED
        std::cout << "PresidentialPardonForm for " << _target << " copy assigned." << std::endl;
    #endif
    return (*this);
}

////////////////////////////////////////////////////////////////////////////////
// member functions: private
////////////////////////////////////////////////////////////////////////////////

void    PresidentialPardonForm::beExecute(Bureaucrat const& executor) const
{
    (void)executor;
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}