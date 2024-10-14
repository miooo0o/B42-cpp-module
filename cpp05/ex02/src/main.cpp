/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:04:54 by minakim           #+#    #+#             */
/*   Updated: 2024/10/12 12:36:18 by minakim          ###   ########.fr       */
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
    std::string target("Guri Guri");
    std::string name("Mina Kim");

	try
    {
        ShrubberyCreationForm form(target);
        Bureaucrat bureaucrat(name, 1);

        bureaucrat.signForm(form);
        bureaucrat.executeForm(form);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}