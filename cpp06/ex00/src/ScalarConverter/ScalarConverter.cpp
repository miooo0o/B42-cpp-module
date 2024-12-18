/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 21:47:02 by minakim           #+#    #+#             */
/*   Updated: 2024/10/26 14:43:24 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

////////////////////////////////////////////////////////////////////////////////
// Public methods
////////////////////////////////////////////////////////////////////////////////

/// @brief The `ScalarConverter` class has a static method convert that takes
///	a string as input and converts it to a char, int, float, or double.
void    ScalarConverter::convert(const std::string& input) {
	
	try
	{
		double value = parseInput(input);

		convertToChar(value);
		convertToInt(value);
		convertToFloat(value);
		convertToDouble(value);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: "<< e.what() << '\n';
	}
}

////////////////////////////////////////////////////////////////////////////////
// Private methods
////////////////////////////////////////////////////////////////////////////////

double	ScalarConverter::parseInput(const std::string& input)
{
	if (input == "nan" || input == "nanf")
		return (NAN);
    if (input == "+inf" || input == "+inff")
		return (INFINITY);
    if (input == "-inf" || input == "-inff")
		return (-INFINITY);
	
	

	if (input.size() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]))
        return (static_cast<double>(input[0]));
	
	std::string			cleanedInput = checkFormatting(input);
	std::istringstream	iss(cleanedInput);
	double				value;

	iss >> value;
	if (iss.fail() || !iss.eof())
		throw std::invalid_argument("Invalid input format: cannot convert to a number");
	return (value);
}


std::string	ScalarConverter::checkFormatting(const std::string& input)
{
	int dotCount = 0;
    for (std::size_t i = 0; i < input.size(); ++i)
	{
        if (input[i] == '.')
            ++dotCount;
        if (dotCount > 1)
            throw std::invalid_argument("Invalid input format: multiple '.' characters");
    }

	std::string cleanedInput = input;
    if (input.back() == 'f')
        cleanedInput = input.substr(0, input.size() - 1);
	return (cleanedInput);
}

////////////////////////////////////////////////////////////////////////////////

void	ScalarConverter::convertToChar(double value)
{
	std::cout << "char: ";
	if (std::isnan(value) || std::isinf(value) || value < CHAR_MIN || value > CHAR_MAX)
		std::cout << "impossible" << std::endl;
	else if (std::isprint(static_cast<char>(value)))
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

void   ScalarConverter::convertToInt(double value)
{
	std::cout << "int: ";
	if (std::isnan(value) || std::isinf(value) || value < INT_MIN || value > INT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;
}

void	ScalarConverter::convertToFloat(double value)
{
	std::cout << "float: ";
	if (std::isnan(value))
		std::cout << "nanf" << std::endl;
	else if (std::isinf(value))
		std::cout << (value < 0 ? "-inff" : "+inff") << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
}

void	ScalarConverter::convertToDouble(double value)
{
	std::cout << "double: ";
	if (std::isnan(value))
		std::cout << "nan" << std::endl;
	else if (std::isinf(value))
		std::cout << (value < 0 ? "-inf" : "+inf") << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << value << std::endl;
}
