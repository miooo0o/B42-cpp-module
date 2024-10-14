/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 21:47:02 by minakim           #+#    #+#             */
/*   Updated: 2024/10/14 21:58:45 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/// @brief Objective:
/// 1. handling errors differently depending on the situation. Handle critical errors and simple errors differently.
/// 2. handle “type distinction” and “conversion” differently.
/// 3. ensure that a function can only be responsible for one thing.

////////////////////////////////////////////////////////////////////////////////
// Public methods
////////////////////////////////////////////////////////////////////////////////

/// @brief The `ScalarConverter` class has a static method convert that takes
///	a string as input and converts it to a char, int, float, or double.
void    ScalarConverter::convert(const std::string& input) {
	
	try
	{
		Type type = detectType(input);
		switch (type)
		{
			case CHAR:
				convertToChar(input);
				break;
			case INT:
				convertToInt(input);
				break;
			case FLOAT:
				convertToFloat(input);
				break;
			case DOUBLE:
				convertToDouble(input);
				break;
			default:
				invalidInput("Unrecognized type"); // exepction?
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: "<< e.what() << '\n';
	}
}

////////////////////////////////////////////////////////////////////////////////
// Private methods : Type detection
////////////////////////////////////////////////////////////////////////////////

ScalarConverter::Type ScalarConverter::detectType(const std::string& input)
{
	if (isChar(input))
		return CHAR;
	else if (isDouble(input))
		return DOUBLE;
	else if (isFloat(input))
		return FLOAT;
	else if (isInt(input))
		return INT;
	return INVALID;
}

bool    ScalarConverter::isChar(const std::string& input)
{
	return (input.length() == 1 && !isdigit(input[0]) && isprint(input[0]));
}

bool    ScalarConverter::isInt(const std::string& input)
{
	std::istringstream iss(input);
	long long ll;
	
	iss >> ll;
	if (iss.fail() && !iss.eof())
		throw ScalarConverter::ConversionFailException();
	if (ll < std::numeric_limits<int>::min() || ll > std::numeric_limits<int>::max())
		throw std::out_of_range("Int overflow");
	return (true);
}

bool    ScalarConverter::isFloat(const std::string& input)
{
	if (input == "nanf" || input == "+inff" || input == "-inff")
		return (true);
	if (input.back() != 'f')
	{
		invalidInput("to convert float, end of input must have 'f' (e.g., 42.0f)");
		return (false);
	}
	if (input.find('.') == std::string::npos)
	{
		invalidInput("to convert float, input must have '.' (e.g., 42.0f)");
		return (false);
	}
	std::string floatPart = input.substr(0, input.length() - 1);
	std::istringstream iss(floatPart);
	float f;
	iss >> f;
	if (iss.fail() && !iss.eof())
		throw ScalarConverter::ConversionFailException();
	if (f < std::numeric_limits<float>::min() || f > std::numeric_limits<float>::max())
        throw std::out_of_range("Float overflow");
	return (true);
}

bool    ScalarConverter::isDouble(const std::string& input)
{
	if (input == "nan" || input == "+inf" || input == "-inf")
		return (true);
	if (input.find('.') == std::string::npos)
    {
		invalidInput("to convert double, input must have '.' (e.g., 42.0)");
		return (false);
	}
	std::istringstream iss(input);
	double d;
	iss >> d;
	if (iss.fail() && !iss.eof())
		throw ScalarConverter::ConversionFailException();
	if (d < std::numeric_limits<double>::min() || d > std::numeric_limits<double>::max())
		throw std::out_of_range("Double overflow");
	return (true);
}

////////////////////////////////////////////////////////////////////////////////
// Private methods : Conversion
////////////////////////////////////////////////////////////////////////////////

void    ScalarConverter::convertToChar(const std::string& input)
{

}

void	ScalarConverter::convertToInt(const std::string& input)
{

}

////////////////////////////////////////////////////////////////////////////////
// Private methods : Print table
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Private methods : Error handling
////////////////////////////////////////////////////////////////////////////////

void	ScalarConverter::invalidInput(const std::string& msg)
{
	std::cerr << "Error: " << msg << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
// Private methods : Exception classes
////////////////////////////////////////////////////////////////////////////////

const char* ScalarConverter::ConversionFailException::what() const throw()
{
	return ("A critical error occurred during the conversion process.");
}