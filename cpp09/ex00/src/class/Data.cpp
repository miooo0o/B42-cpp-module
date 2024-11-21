/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:03:12 by minakim           #+#    #+#             */
/*   Updated: 2024/11/21 22:27:49 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"

Date::Date(const std::string& date)
{
	_parse(date);
}

Date::~Date()
{
}

// default constructor, not used
Date::Date()
{
}

//////////////////////////////////////////////////////////////////////////////
// operator overload
//////////////////////////////////////////////////////////////////////////////
bool	Date::operator<(const Date& other) const
{
	return (_year < other._year ||
		(_year == other._year && (_month < other._month ||
		(_month == other._month && _day < other._day))));
}

bool	Date::operator>(const Date& other) const
{
	return (other < *this);
}

bool	Date::operator==(const Date& other) const
{
	return (_year == other._year && _month == other._month && _day == other._day);
}

bool	Date::operator>=(const Date& other) const
{
	return (*this > other || *this == other);
}

bool	Date::operator<=(const Date& other) const
{
	return (other >= *this);
}

bool	Date::operator!=(const Date& other) const
{
	return (!(*this == other));
}

std::ostream&	operator<<(std::ostream& os, const Date& date)
{
	os << date.getYear() << "-" << date.getMonth() << "-" << date.getDay();
	return (os);
}

//////////////////////////////////////////////////////////////////////////////
// member functions
//////////////////////////////////////////////////////////////////////////////

void	Date::_isValid()
{
	static const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (_month < 1 || _month > 12)
		throw std::invalid_argument("Invalid date: month out of range");
	int maxDays = daysInMonth[_month - 1];
	if (_month == 2 && (_isLeapYear(_year)))
		maxDays = 29;
	if (_day < 1 || _day > maxDays)
		throw std::invalid_argument("Invalid date: day out of range");
}

void	Date::_parse(const std::string& date)
{
	if (date.size() != 10)
		throw std::invalid_argument("Invalid date format");
	if (date[4] != '-' || date[7] != '-')
		throw std::invalid_argument("Invalid date format");

	std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 2);
	std::string day = date.substr(8, 2);

	if (year.find_first_not_of("0123456789") != std::string::npos ||
		month.find_first_not_of("0123456789") != std::string::npos ||
		day.find_first_not_of("0123456789") != std::string::npos)
		throw std::invalid_argument("Invalid date format");
	try
	{
		_year = std::stoi(year);
		_month = std::stoi(month);
		_day = std::stoi(day);
	}
	catch (const std::exception& e)
	{
		throw std::invalid_argument("Invalid date format");
	}
	_isValid();
}

//////////////////////////////////////////////////////////////////////////////

bool	Date::_isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

size_t Date::_daysFromStart(const Date& date) const
{
	static const int	daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int                 year = date.getYear();
	int                 month = date.getMonth();
	int                 day = date.getDay();
	size_t              totalDays;

	totalDays = year * 365 + (year / 4 - year / 100 + year / 400);
	for (int i = 0; i < month - 1; ++i)
	{
		totalDays += daysInMonth[i];
		if (i == 1 && _isLeapYear(year))
			totalDays += 1;
	}
	totalDays += day;
	return (totalDays);
}

size_t Date::getDaySpan(const Date& date) const
{
	size_t span = _daysFromStart(date) - _daysFromStart(*this);
	return ( span < 0 ? -span : span );
}

//////////////////////////////////////////////////////////////////////////////
/// getters
//////////////////////////////////////////////////////////////////////////////

int	Date::getYear() const
{
	return (_year);
}

int	Date::getMonth() const
{
	return (_month);
}

int	Date::getDay() const
{
	return (_day);
}