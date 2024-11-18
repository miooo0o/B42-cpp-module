/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:31:00 by minakim           #+#    #+#             */
/*   Updated: 2024/11/18 17:21:29 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

////////////////////////////////////////////////////////////////////////////////
/// Constructor, destructor
////////////////////////////////////////////////////////////////////////////////

/// @brief constructor
/// @param storageLimit the class can store a maximum of `storageLimit` integers
Span::Span(const unsigned int storageLimit)
	: _storageLimit(storageLimit)
{
}

/// @brief private constructor, not used
Span::Span()
	: _storageLimit(0)
{
}

Span::~Span()
{
}

////////////////////////////////////////////////////////////////////////////////
/// Copy constructor, assignment operator
////////////////////////////////////////////////////////////////////////////////

Span::Span(const Span &other)
	: _numbers(other._numbers), _storageLimit(other._storageLimit)
{
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_numbers = other._numbers;
		_storageLimit = other._storageLimit;
	}
	return (*this);
}

////////////////////////////////////////////////////////////////////////////////
/// Member functions
////////////////////////////////////////////////////////////////////////////////

void    Span::addNumber(const int number)
{
	if (_numbers.size() >= _storageLimit)
		throw std::length_error("Storage limit reached");
	// std::cout << "  adding: " << number << "..." << std::endl;
	_numbers.push_back(number);
}

unsigned int    Span::shortestSpan() const
{
	if (_numbers.size() <= 1)
		throw std::length_error("Not enough numbers to calculate span");

	std::vector<int>	sortedNumbers(_numbers.begin(), _numbers.end());
	unsigned int          		shortestSpan;

	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	shortestSpan = std::numeric_limits<unsigned int>::max();
	for (size_t i = 1; i < sortedNumbers.size(); i++)
	{
		unsigned int	span = sortedNumbers[i] - sortedNumbers[i - 1];
		shortestSpan = std::min(shortestSpan, span);
	}
	return (shortestSpan);
}

unsigned int	Span::longestSpan() const
{
	if (_numbers.size() <= 1)
		throw std::length_error("Not enough numbers to calculate span");
	unsigned int	maxEle = *std::max_element(_numbers.begin(), _numbers.end());
	unsigned int	minEle = *std::min_element(_numbers.begin(), _numbers.end());
	int				span = maxEle - minEle;
	return (span > 0 ? span : span * -1);
}

////////////////////////////////////////////////////////////////////////////////
