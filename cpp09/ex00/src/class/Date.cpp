/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:03:12 by minakim           #+#    #+#             */
/*   Updated: 2024/11/27 20:33:28 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"

Date::Date(const std::string& date)
	: _year(0), _month(0), _day(0)
{
	_parse(date);
}

Date::~Date()
{
}

// default constructor, not used
Date::Date()
	: _year(0), _month(0), _day(0)
{
}

//////////////////////////////////////////////////////////////////////////////
// operator overload
//////////////////////////////////////////////////////////////////////////////
///
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
//////////////////////////////////////////////////////////////////////////////

std::string	Date::toString() const
{
	std::string	prefixMonth;
	std::string	prefixDay;
	if (_year < 1000 || _year > 9999)
		throw std::out_of_range("Date should be 4 characters.");
	if (_month >= 1 && _month <= 9)
		prefixMonth = "0";
	if (_day >= 1 && _day <= 9)
		prefixDay = "0";
	// FIXME: can't use to_string
	return (std::to_string(_year) + "-" + prefixMonth + std::to_string(_month) + "-" + prefixDay + std::to_string(_day));
}

std::ostream&	operator<<(std::ostream& os, const Date& date)
{
	os << date.toString();
	return (os);
}

//////////////////////////////////////////////////////////////////////////////
// member functions
//////////////////////////////////////////////////////////////////////////////

bool	Date::isValid() const
{
	static const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (_month < 1 || _month > 12)
		return (false);
	int maxDays = daysInMonth[_month - 1];
	if (_month == 2 && (_isLeapYear(_year)))
		maxDays = 29;
	if (_day < 1 || _day > maxDays)
		return (false);
	return (true);
}

void	Date::_parse(const std::string& date)
{
	if (date.empty())
		throw std::invalid_argument("Invalid date format: empty string");
	std::string trimmedDate = trim(date);
	if (trimmedDate.size() != 10)
		throw std::invalid_argument("Invalid date format: " + trimmedDate);
	if (trimmedDate[4] != '-' || trimmedDate[7] != '-')
		throw std::invalid_argument("Invalid date format: " + trimmedDate);
	std::string year = trimmedDate.substr(0, 4);
	std::string month = trimmedDate.substr(5, 2);
	std::string day = trimmedDate.substr(8, 2);
	if (year.find_first_not_of("0123456789") != std::string::npos ||
		month.find_first_not_of("0123456789") != std::string::npos ||
		day.find_first_not_of("0123456789") != std::string::npos)
		throw std::invalid_argument("Invalid date format: " + year + "-" + month + "-" + day);
	_year = std::stoi(year);
	_month = std::stoi(month);
	_day = std::stoi(day);
}

std::string	Date::trim(const std::string& line)
{
	std::string	trimmed = line;
	trimmed.erase(0, trimmed.find_first_not_of(' '));
	trimmed.erase(trimmed.find_last_not_of(' ') + 1);
	return (trimmed);
}

//////////////////////////////////////////////////////////////////////////////

bool	Date::_isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

size_t Date::_daysFromStart(const Date& date) const
{
	static const int	daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int                 year	= date.getYear();
	int                 month	= date.getMonth();
	int                 day		= date.getDay();
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
	return ( _daysFromStart(date) - _daysFromStart(*this) );
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