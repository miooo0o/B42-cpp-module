/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:27:49 by minakim           #+#    #+#             */
/*   Updated: 2024/09/30 16:56:00 by minakim          ###   ########.fr       */
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
}

/// @brief constructor, public 
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm(target, 145, 137)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

////////////////////////////////////////////////////////////////////////////////
// copy constructor & assignation operator
////////////////////////////////////////////////////////////////////////////////

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other)
{
}

ShrubberyCreationForm&
	ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

////////////////////////////////////////////////////////////////////////////////
// member functions: private
////////////////////////////////////////////////////////////////////////////////

void    ShrubberyCreationForm::execute(Bureaucrat const &executor) const
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