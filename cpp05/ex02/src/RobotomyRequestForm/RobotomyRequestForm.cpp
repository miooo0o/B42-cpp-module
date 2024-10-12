/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:28:06 by minakim           #+#    #+#             */
/*   Updated: 2024/10/12 12:30:41 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

////////////////////////////////////////////////////////////////////////////////
// constructor & destructor
////////////////////////////////////////////////////////////////////////////////

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("Robotomy Request Form", 72, 45)
{
	#ifndef MUTED
		 std::cout << "RobotomyRequestForm created." << std::endl;
		std::cout << "grades: sign 72, exec 45 as default" << std::endl;
	#endif
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("Robotomy Request Form", 72, 45), _target(target)
{
    #ifndef MUTED
        std::cout << "RobotomyRequestForm created for " << _target << "." << std::endl;
        std::cout << "Grades: sign 72, exec 45" << std::endl;
    #endif
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    #ifndef MUTED
        std::cout << "RobotomyRequestForm for " << _target << " dismissed." << std::endl;
    #endif    
}

////////////////////////////////////////////////////////////////////////////////
// copy constructor & assignation operator
////////////////////////////////////////////////////////////////////////////////

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), _target(other._target)
{
    #ifndef MUTED
        std::cout << "RobotomyRequestForm for " << _target << " copy constructed." << std::endl;
    #endif
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    #ifndef MUTED
        std::cout << "RobotomyRequestForm for " << _target << " copy assigned." << std::endl;
    #endif
	return (*this);
}


////////////////////////////////////////////////////////////////////////////////
// member functions: private
////////////////////////////////////////////////////////////////////////////////

void	RobotomyRequestForm::beExecute(Bureaucrat const &executor) const
{
    (void)executor;
    std::cout << "(drilling noises---!) " << std::flush;
    srand(static_cast<unsigned int>(time(0)));
    int getRandom = rand() % 2;

    if (getRandom)
        std::cout << _target << " has been robotomized successfully." << std::endl;
    else
        std::cout << _target << " robotomy failed." << std::endl;
}