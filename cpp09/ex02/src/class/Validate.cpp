/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Validate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:02:25 by minakim           #+#    #+#             */
/*   Updated: 2025/01/16 13:39:41 by minakim          ###   ########.fr       */
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

bool	Validate::isValidate() const
{
	return (isInitialized);
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
			elements.push_back(std::atoi(token.c_str()));
			count++;
		}
		else
			throw std::invalid_argument("invalid input: not a digit [" + token + "]");
	}
}


/* getter */

int	Validate::getCount()
{
	return (count);
}

std::list<int> Validate::getElements()
{
	return (elements);
}
