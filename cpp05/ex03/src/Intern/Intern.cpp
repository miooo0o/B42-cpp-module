/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:44:24 by minakim           #+#    #+#             */
/*   Updated: 2024/10/14 17:57:10 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Because filling out forms is annoying enough, it would be cruel to ask our bureaucrats
to do this all day long. Fortunately, interns exist. In this exercise, you have to implement
the Intern class. The intern has no name, no grade, no unique characteristics. The only
thing the bureaucrats care about is that they do their job.

However, the intern has one important capacity: the makeForm() function. It takes
two strings. The first one is the name of a form and the second one is the target of the
form. It return a pointer to a Form object (whose name is the one passed as parameter)
whose target will be initialized to the second parameter.

It will print something like:
	```
	Intern creates <form>
	```
If the form name passed as parameter doesn’t exist, print an explicit error message.

You must avoid unreadable and ugly solutions like using a if/elseif/else forest. This
kind of things won’t be accepted during the evaluation process. You’re not in Piscine
(pool) anymore. As usual, you have to test that everything works as expected.
*/

#include "Intern.hpp"

////////////////////////////////////////////////////////////////////////////////
// constructor & destructor
////////////////////////////////////////////////////////////////////////////////

Intern::Intern()
{
	#ifndef MUTED
		std::cout << "Sad Intern created." << std::endl;
	#endif
}

Intern::~Intern()
{
	#ifndef MUTED
		std::cout << "Sad Intern dismissed. " << std::endl;
	#endif
}

////////////////////////////////////////////////////////////////////////////////
// copy constructor & assignation operator
////////////////////////////////////////////////////////////////////////////////

Intern::Intern(const Intern&)
{
	#ifndef MUTED
		std::cout << "Sad Intern copy constucted. Nothing happen." << std::endl;
	#endif
}

Intern& Intern::operator=(const Intern&)
{
	#ifndef MUTED
		std::cout << "Sad Intern copy assigned. return itself." << std::endl;
	#endif
	return (*this);
}

////////////////////////////////////////////////////////////////////////////////
// member functions: Public
////////////////////////////////////////////////////////////////////////////////

Form*   Intern::makeForm(const std::string& formName, const std::string& target)
{
	static std::map<std::string, FormCreator> map;
	if (map.empty())
	{
		map["shrubbery creation"] = &Intern::makeShrubbery;
		map["robotomy request"] = &Intern::makeRobotomy;
		map["presidential pardon"] = &Intern::makePresidential;
	}

	if (map.find(formName) == map.end())
		throw FormNotFoundException();
	std::cout << "Sad Intern creates \"" << formName << "\"." << std::endl;
	return (map[formName](target));
}

const char* Intern::FormNotFoundException::what() const throw()
{
	return ("Form not found.");
}

////////////////////////////////////////////////////////////////////////////////
// member functions: Private
////////////////////////////////////////////////////////////////////////////////

Form*	Intern::makeShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

Form*	Intern::makeRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

Form*	Intern::makePresidential(std::string target)
{
	return (new PresidentialPardonForm(target));
}