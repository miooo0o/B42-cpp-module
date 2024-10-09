/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:27:49 by minakim           #+#    #+#             */
/*   Updated: 2024/10/09 17:12:16 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

////////////////////////////////////////////////////////////////////////////////
// constructor & destructor
////////////////////////////////////////////////////////////////////////////////

/// @brief default constructor, private
ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("default", 145, 137)
{    
	 #ifndef MUTED
        std::cout << "Shrubbery " << getName() << " hired." << std::endl;
        std::cout << "grades: sign 145, exec 137 as default" << std::endl;
    #endif
}

/// @brief constructor, public 
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm(target, 145, 137)
{
	#ifndef MUTED
        std::cout << "Shrubbery " << getName() << " hired." << std::endl;
        std::cout << "grades: sign " << getMinSignGrade() << ", exec " << getMinExecGrade() << std::endl;
    #endif
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	#ifndef MUTED
        std::cout << "Shrubbery " << getName() << " dismissed." << std::endl;
    #endif
}

////////////////////////////////////////////////////////////////////////////////
// copy constructor & assignation operator
////////////////////////////////////////////////////////////////////////////////

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other)
{
	#ifndef MUTED
        std::cout << "Shrubbery " << getName() << " dismissed." << std::endl;
    #endif
}

ShrubberyCreationForm&
	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
		AForm::operator=(other);
    #ifndef MUTED
        std::cout << "Shrubbery " << getName() << " copy assigned." << std::endl;
    #endif	
	return (*this);
}

////////////////////////////////////////////////////////////////////////////////
// member functions: private
////////////////////////////////////////////////////////////////////////////////

void    ShrubberyCreationForm::beExecute(Bureaucrat const &executor) const
{
	std::ofstream   outfile;

	outfile.open(this->getName() + "_shrubbery");
	if (outfile.is_open())
	{
		outfile << "      _-_\n"
				<< "   /~~   ~~\\\n"
				<< " /~~         ~~\\\n"
				<< "{               }\n"
				<< " \\  _-     -_  /\n"
				<< "   ~  \\\\ //  ~\n"
				<< "_- -   | | _- _\n"
				<< "  _ -  | |   -_\n"
				<< "      // \\\n";
		outfile.close();
	}
	else
		throw ShrubberyCreationForm::FileOpenException();
	
}

////////////////////////////////////////////////////////////////////////////////

const char* ShrubberyCreationForm::FileOpenException::what() const throw()
{
	return ("File open error");
}