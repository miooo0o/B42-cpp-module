# pragma once

#include <string>

class Date
{
private:
	int	_year;
	int	_month;
	int	_day;
public:
	Date(const std::string& date);
	~Date();

	bool operator<(const Date& other) const;
	bool operator>(const Date& other) const;
    bool operator==(const Date& other) const;
	bool operator>=(const Date& other) const;
	bool operator<=(const Date& other) const;
	bool operator!=(const Date& other) const;

	bool		isValid();

private:

	void	_parse(const std::string& date);
};
