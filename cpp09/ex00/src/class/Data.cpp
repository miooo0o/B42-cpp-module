#include "Date.hpp"

Date::Date(const std::string& date)
{
    _parse(date);
}

Date::~Date()
{
}

bool	Date::isValid()
{
    if (_month < 1 || _month > 12)
        return (false);
    if (_day < 1 || _day > 31)
        return (false);
	return (true);
}


void	Date::_parse(const std::string& date)
{
    if (date.size() != 10)
        throw std::invalid_argument("Invalid date format");
    if (date[4] != '-' || date[7] != '-')
        throw std::invalid_argument("Invalid date format");

    std::string year = date.substr(0, 3);
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

}
