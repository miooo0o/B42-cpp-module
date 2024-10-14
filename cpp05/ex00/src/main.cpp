/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:04:54 by minakim           #+#    #+#             */
/*   Updated: 2024/09/19 16:10:02 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <sstream>
#include <iostream>

std::string testExpectation(bool expectation)
{
    std::string         what_should_be = expectation ? "OK" : "KO";
    std::ostringstream  result;
    result << "Expected: " << what_should_be << "\n";
    return (result.str());
}

std::string testConstructor(const std::string& name, int grade, bool expectation)
{
    std::ostringstream result;
    result << testExpectation(expectation);

    try
    {
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
        result << "[OK] `" << target.getName() << "` new grade is: " << target.getGrade() << "\n";
    }
    catch(const std::exception& e)
    {
        result << "[KO] Exception caught: " << e.what() << '\n';
    }
    return (result.str());
}

int main(void)
{
    std::cout << "=================== Test: Constructor ===================\n"
              << testConstructor("Mina Kim", 1, true)
              << testConstructor("Mina Kim", 150, true)
              << testConstructor("Mina Kim", -1, false)
              << testConstructor("Mina Kim", 170, false);

    std::cout << "\n=================== Test: Grade Adjustment ===================\n";

    Bureaucrat middleMina("middle Mina", 75);
    std::cout << "\n[" << middleMina << "]\n"
			  << "Increment Grade, "
              << testNewGrade(middleMina, true, &Bureaucrat::incrementGrade)
              << "Decrement Grade, "
			  << testNewGrade(middleMina, true, &Bureaucrat::decrementGrade);

    Bureaucrat girlTooHigh("Too High", 1);
    std::cout << "\n[" << girlTooHigh << "]\n"
			  << "Increment Grade, "
              << testNewGrade(girlTooHigh, false, &Bureaucrat::incrementGrade)
			  << "Decrement Grade, "
              << testNewGrade(girlTooHigh, true, &Bureaucrat::decrementGrade);

    Bureaucrat girlTooLow("Too Low", 150);
    std::cout << "\n[" << girlTooLow << "]\n"
			  << "Decrement Grade, "
              << testNewGrade(girlTooLow, false, &Bureaucrat::decrementGrade)
			  << "Increment Grade, "
              << testNewGrade(girlTooLow, true, &Bureaucrat::incrementGrade);

    std::cout << "\n======================= Test Done =======================\n";
    return (0);
}