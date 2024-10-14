#include "PresidentialPardonForm.hpp"

////////////////////////////////////////////////////////////////////////////////
// constructor & destructor
////////////////////////////////////////////////////////////////////////////////

PresidentialPardonForm::PresidentialPardonForm()
    : Form("Presidential Pardon Form", 25, 5)
{
    #ifndef MUTED
        std::cout << "PresidentialPardonForm created (Sign grade: 25, Exec grade: 5)." << std::endl;
        std::cout << "Grades: sign 25, exec 5" << std::endl;
    #endif
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : Form("Presidential Pardon Form", 25, 5), _target(target)
{
    #ifndef MUTED
        std::cout << "PresidentialPardonForm created for " << _target 
          << " (Sign grade: 25, Exec grade: 5)." << std::endl;
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
    : Form(other), _target(other._target)
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
        Form::operator=(other);
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