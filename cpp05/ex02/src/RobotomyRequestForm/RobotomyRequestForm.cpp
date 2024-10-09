/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:28:06 by minakim           #+#    #+#             */
/*   Updated: 2024/10/09 17:12:16 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

////////////////////////////////////////////////////////////////////////////////
// constructor & destructor
////////////////////////////////////////////////////////////////////////////////

RobotomyRequestForm::RobotomyRequestForm()
	:AForm("default", 72, 45)
{
	#ifndef MUTED
		std::cout << "Robotomy " << getName() << " hired." << std::endl;
		std::cout << "grades: sign 72, exec 45 as default" << std::endl;
	#endif
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	:AForm(target, 72, 45)
{
	#ifndef MUTED
		std::cout << "Robotomy " << getName() << " hired." << std::endl;
		std::cout << "grades: sign " << getMinSignGrade() << ", exec " << getMinExecGrade() << std::endl;
	#endif
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	#ifndef MUTED
        std::cout << "Robotomy " << getName() << " dismissed." << std::endl;
    #endif
}

////////////////////////////////////////////////////////////////////////////////
// copy constructor & assignation operator
////////////////////////////////////////////////////////////////////////////////

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other)
{
	 #ifndef MUTED
        std::cout << "Robotomy " << getName() << " copy constructed." << std::endl;
    #endif
}

RobotomyRequestForm&
	RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
		AForm::operator=(other);
	#ifndef MUTED
        std::cout << "Robotomy " << getName() << " copy assigned." << std::endl;
    #endif
	return (*this);
}


////////////////////////////////////////////////////////////////////////////////
// member functions: private
////////////////////////////////////////////////////////////////////////////////

void	RobotomyRequestForm::beExecute(Bureaucrat const &executor) const
{
	std::cout << "(drilling noises---!) " << std::flush;
	srand(static_cast<unsigned int>(time(0)));
	int getRandom = rand() % 2;
	if (getRandom)
		std::cout << getName() << " has been robotomized successfull."
			<< std::endl;
	else
		std::cout << getName() << " robotomy failed."
			<< std::endl;
}