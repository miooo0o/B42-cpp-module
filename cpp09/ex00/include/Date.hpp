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

	bool	operator<(const Date& other) const;
	bool	operator>(const Date& other) const;
    bool	operator==(const Date& other) const;
	bool	operator>=(const Date& other) const;
	bool	operator<=(const Date& other) const;
	bool	operator!=(const Date& other) const;

	size_t		getDaySpan(const Date& date) const;
	int			getYear() const;
	int			getMonth() const;
	int			getDay() const;
	std::string	toString() const;
	bool		isValid() const;

	static std::string	trim(const std::string& line);

private:
	void		_parse(const std::string& date);
	static bool	_isLeapYear(int year);
	size_t		_daysFromStart(const Date& date) const;


	Date(); // default constructor, not used
};

std::ostream&	operator<<(std::ostream& os, const Date& date);
