/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:27:49 by minakim           #+#    #+#             */
/*   Updated: 2024/10/14 18:13:33 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

////////////////////////////////////////////////////////////////////////////////
// constructor & destructor
////////////////////////////////////////////////////////////////////////////////

/// @brief default constructor, private
ShrubberyCreationForm::ShrubberyCreationForm()
	: Form("Shrubbery Creation Form", 145, 137)
{    
	 #ifndef MUTED
        std::cout << "ShrubberyCreationForm created  (Sign grade: 145, Exec grade: 137)." << std::endl;
    #endif
}

/// @brief constructor, public 
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : Form("Shrubbery Creation Form", 145, 137), _target(target)
{
    #ifndef MUTED
        std::cout << "ShrubberyCreationForm created for " << _target
			<< " (Sign grade: 145, Exec grade: 137)." << std::endl;
    #endif
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    #ifndef MUTED
        std::cout << "ShrubberyCreationForm for " << _target << " dismissed." << std::endl;
    #endif    
}

////////////////////////////////////////////////////////////////////////////////
// copy constructor & assignation operator
////////////////////////////////////////////////////////////////////////////////

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : Form(other), _target(other._target)
{
    #ifndef MUTED
        std::cout << "ShrubberyCreationForm for " << _target << " copy constructed." << std::endl;
    #endif
}

ShrubberyCreationForm&
	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        Form::operator=(other);
        _target = other._target;
    }
    #ifndef MUTED
        std::cout << "ShrubberyCreationForm for " << _target << " copy assigned." << std::endl;
    #endif
	return (*this);
}

////////////////////////////////////////////////////////////////////////////////
// member functions: private
////////////////////////////////////////////////////////////////////////////////

void    ShrubberyCreationForm::beExecute(Bureaucrat const &executor) const
{
	std::ofstream   outfile;
	std::string		filename(_target + "_shrubbery");

	outfile.open(filename.c_str());
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
		std::cout << "file, \"" << filename << "\" created for " << _target << "." << std::endl;
	}
	else
		throw ShrubberyCreationForm::FileOpenException();
	
}

////////////////////////////////////////////////////////////////////////////////

const char* ShrubberyCreationForm::FileOpenException::what() const throw()
{
	return ("File open error: Could not create shrubbery file.");
}