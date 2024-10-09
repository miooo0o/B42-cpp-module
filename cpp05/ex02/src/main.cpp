/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:04:54 by minakim           #+#    #+#             */
/*   Updated: 2024/10/09 16:56:18 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

#include <sstream>
#include <iostream>

int main()
{
	try
    {
        Bureaucrat bob("Bob", 42);
        std::cout << bob << std::endl;

        PresidentialPardonForm pardon("Alice");
        bob.signForm(pardon);
        bob.executeForm(pardon);

        ShrubberyCreationForm shrubbery("Garden");
        bob.signForm(shrubbery);
        bob.executeForm(shrubbery);

        RobotomyRequestForm robotomy("Marvin");
        bob.signForm(robotomy);
        bob.executeForm(robotomy);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}