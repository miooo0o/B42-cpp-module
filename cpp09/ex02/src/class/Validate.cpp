/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Validate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:02:25 by minakim           #+#    #+#             */
/*   Updated: 2025/01/29 15:48:41 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Validate.hpp"

Validate::Validate(const int& argc, char** args)
	: count(0), elements(), isInitialized(false)
{
	if (argc > 1)
	{
		for (int i = 1; i < argc; ++i)
		{
			std::string	trimmed = trim(args[i]);
			processArg(trimmed);
		}
		if (!elements.empty() && elements.size()== count)
			isInitialized = true;
	}
	
}

Validate::~Validate()
{
}

bool	Validate::empty() const
{
	if (count == 0 && elements.empty())
		return (true);
	if (!elements.empty() && count > 0 && elements.size() == count)
		return (false);
	throw std::runtime_error("runtime error: class-Validate() unset");
}

std::string	Validate::trim(char* arg)
{
	std::string	str(arg);
	std::size_t	first;
	std::size_t	last;

	first = str.find_first_not_of(" \t");
	if (first == std::string::npos)
        return ("");
	last = str.find_last_not_of(" \t");
	return (str.substr(first, (last - first + 1)));
}

bool	Validate::isNumber(std::string& str) const
{
	size_t	i = 0;

	if (str[0] == '+')
		i++;
	if (str[0] == '-')
		throw std::invalid_argument("invalid input: negertive sign at [" + str + "]");
	for (; i < str.size(); ++i)
	{
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}

bool	Validate::isInterger(std::string& str) const
{
	std::istringstream	iss(str);
	double				stash;

	iss >> stash;
	if (stash > INT_MAX || stash < INT_MIN)
		throw std::invalid_argument("invalid input: number too large or small [" + str + "]");
	return (true);
}

bool	Validate::isUniqueNumber(const int num) const
{
	if (elements.empty())
		return (true);
	std::list<int>::const_iterator it;
	for (it = elements.begin(); it != elements.end(); ++it)
	{
		if (*it == num)
			return (false);
	}
	return (true);
}

void	Validate::processArg(std::string& arg)
{
	std::istringstream	iss(arg);
    std::string			token;

	while (iss >> token)
	{
		if (token.empty())
    	    throw std::invalid_argument("invalid input: empty string");
		if (isNumber(token) && isInterger(token))
		{
			int num = std::stoi(token);
			if (!isUniqueNumber(num))
				throw std::invalid_argument("invalid input: duplicate number found in the list [" + token + "]");
			elements.push_back(num);
			count++;
		}
		else
			throw std::invalid_argument("invalid input: not a digit [" + token + "]");
	}
}

bool	Validate::validated() const
{
	if (empty())
    {
        std::cerr << "error: empty input." << std::endl;
        std::cerr << "Usage: ./PmergeMe <number1> <number2> ... <numberN>" << std::endl;
        return (false);
    }
    if (getCount() < 2)
    {
        std::cerr << "error: insufficient input. Please provide at least two numbers." << std::endl;
        std::cerr << "Usage: ./PmergeMe <number1> <number2> ... <numberN>" << std::endl;
        return (false);

    }
    if (!getValidate())
    {
		std::cerr << "error: validation failed. Unable to proceed with the given input." << std::endl;
        return (false);

    }
	return (true);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
// Getter
//////////////////////////////////////////////////////////////////////////////////////////////////////


int	Validate::getCount() const
{
	return (count);
}

std::list<int> Validate::getElements()
{
	return (elements);
}

bool	Validate::getValidate() const
{
	return (isInitialized);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////
// Test Method
//////////////////////////////////////////////////////////////////////////////////////////////////////


void	Validate::print()
{
	std::cout << "element count: " << count << std::endl;
	std::cout << "elements: " << std::flush;
	if (elements.empty())
	{
		std::cout << "empty." << std::endl;
	}
	else
	{
		std::list<int>::const_iterator it;
		for (it = elements.begin(); it != elements.end(); ++it)
		{
			std::cout << "[" << *it << "] " << std::flush;
		}
		std::cout << std::endl;
	}
	std::cout << "initialized: " << std::flush;
	if (isInitialized)
		std::cout << "true." << std::endl;
	else
		std::cout << "false." << std::endl;
}