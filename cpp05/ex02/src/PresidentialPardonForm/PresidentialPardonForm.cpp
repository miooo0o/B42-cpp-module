#include "PresidentialPardonForm.hpp"

////////////////////////////////////////////////////////////////////////////////
// constructor & destructor
////////////////////////////////////////////////////////////////////////////////

PresidentialPardonForm::PresidentialPardonForm()
    :AForm("default", 25, 5)
{
    #ifndef MUTED
		std::cout << "Presidential " << getName() << " hired." << std::endl;
		std::cout << "grades: sign 25, exec 5 as default" << std::endl;
	#endif
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    :AForm(target, 25, 5)
{
    #ifndef MUTED
		std::cout << "Presidential " << getName() << " hired." << std::endl;
		std::cout << "grades: sign " << getMinSignGrade() << ", exec " << getMinExecGrade() << std::endl;
	#endif
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	#ifndef MUTED
        std::cout << "Presidential " << getName() << " dismissed." << std::endl;
    #endif    
}

////////////////////////////////////////////////////////////////////////////////
// copy constructor & assignation operator
////////////////////////////////////////////////////////////////////////////////

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    :AForm(other)
{
	 #ifndef MUTED
        std::cout << "Presidential " << getName() << " copy constructed." << std::endl;
    #endif
}

PresidentialPardonForm&
    PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other)
        AForm::operator=(other);
    #ifndef MUTED
        std::cout << "Presidential " << getName() << " copy assigned." << std::endl;
    #endif
    return (*this);
}

////////////////////////////////////////////////////////////////////////////////
// member functions: private
////////////////////////////////////////////////////////////////////////////////

void    PresidentialPardonForm::beExecute(Bureaucrat const& executor) const
{
    std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox."
        << std::endl;
}