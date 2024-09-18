/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:26:39 by minakim           #+#    #+#             */
/*   Updated: 2024/09/18 21:40:11 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <sstream>

std::string testExpectation(bool expectation)
{
	std::string			what_should_be = expectation ? "OK" : "KO";
	std::string			result;
	result = "Test Result should be " + what_should_be + "\n";
	return (result);
}

std::string	testConstructor(const std::string& name, int grade, bool expectation)
{
	std::ostringstream result;
    result << testExpectation(expectation);

    try
    {
		result << "---------------------------------------------------\n";
        Bureaucrat target(name, grade);
        result << "[OK] " << target << '\n';
    }
    catch (const std::exception& e)
    {
        result << "[KO] Exception caught: " << e.what() << '\n';
    }
    return (result.str());
}

std::string testNewGrade(Bureaucrat& target, bool expectation, void (Bureaucrat::*action)())
{
    std::ostringstream result;
    result << testExpectation(expectation);

    try
    {
        (target.*action)();
        result << "[OK] " << target.getName() << " new grade is: " << target.getGrade() << "\n";
    	result << "---------------------------------------------------\n";
	}
    catch(const std::exception& e)
    {
        result << "[KO] Exception caught: " << e.what() << '\n';
    	result << "---------------------------------------------------\n";
	}
    return (result.str());

}

int main(void)
{
	std::cout << "===================================================\n"
	<< testConstructor("Mina Kim", 1, true) << std::endl;
	std::cout << "\n\n===================================================\n"
	<< testConstructor("Mina Kim", 150, true) << std::endl;
	std::cout << "\n\n===================================================\n"
	<< testConstructor("Mina Kim", -1, false) << std::endl;
	std::cout << "\n\n===================================================\n"
	<< testConstructor("Mina Kim", 170, false) << std::endl;


	Bureaucrat midleMina("Mina Kim", 75);

	std::cout << "\n\n===================================================\n";
	std::cout << midleMina << "\n"
	<< testNewGrade(midleMina, true, &Bureaucrat::incrementGrade)
	<< testNewGrade(midleMina, true, &Bureaucrat::decrementGrade) << std::endl;;

	std::cout << "\n\ntest done." << std::endl;
	return (true);
}
