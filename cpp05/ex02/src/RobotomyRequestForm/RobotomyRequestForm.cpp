/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:28:06 by minakim           #+#    #+#             */
/*   Updated: 2024/10/14 18:18:08 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

////////////////////////////////////////////////////////////////////////////////
// constructor & destructor
////////////////////////////////////////////////////////////////////////////////

RobotomyRequestForm::RobotomyRequestForm()
	: Form("Robotomy Request Form", 72, 45)
{
	#ifndef MUTED
		std::cout << "RobotomyRequestForm created (Sign grade: 72, Exec grade: 45)." << std::endl;
	#endif
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : Form("Robotomy Request Form", 72, 45), _target(target)
{
    #ifndef MUTED
        std::cout << "RobotomyRequestForm created for " << _target 
            << " (Sign grade: 72, Exec grade: 45)." << std::endl;
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
    : Form(other), _target(other._target)
{
    #ifndef MUTED
        std::cout << "RobotomyRequestForm for " << _target << " copy constructed." << std::endl;
    #endif
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        Form::operator=(other);
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
    srand(static_cast<unsigned int>(time(0)));
    int getRandom = rand() % 2;
    
    std::cout << "(drilling noises---!) " << std::flush;
    if (getRandom)
        std::cout << _target << " has been robotomized successfully." << std::endl;
    else
        std::cout << _target << " robotomy failed." << std::endl;
}