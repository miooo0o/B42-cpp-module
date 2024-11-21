/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:50:23 by minakim           #+#    #+#             */
/*   Updated: 2024/11/21 22:30:30 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "Date.hpp"

///////////////////////////////////////////////////////////////////////////////
/// FileHandler
///////////////////////////////////////////////////////////////////////////////

FileHandler::FileHandler(const std::string& filename)
    : _filename(filename)
{
    openFile();
}

FileHandler::~FileHandler()
{
    closeFile();
}

void	FileHandler::openFile()
{
    _file.open(_filename.c_str(), std::ios::in);
    if (!_file.is_open())
        throw std::runtime_error("Error: could not open file " + _filename);
}

 std::vector<std::string>   FileHandler::readFile()
{
    std::vector<std::string> content;
    std::string line;

    while (std::getline(_file, line))
    {
        if (line.empty())
            continue;
        if (line.find("|") == std::string::npos)
            throw std::runtime_error("Error: bad input => " + line);
        content.push_back(line);
    }
    return (content);
}

void	FileHandler::closeFile()
{
    if (_file.is_open())
        _file.close();
}

///////////////////////////////////////////////////////////////////////////////
/// DataBase
///////////////////////////////////////////////////////////////////////////////

Database::Database(const std::vector<std::string>& content)
{
    _parse(content);
}

Database::Database(const Database& other)
{}

Database& Database::operator=(const Database& other)
{}

Database::~Database()
{}


///////////////////////////////////////////////////////////////////////////////

void	Database::_parse(const std::vector<std::string>& content)
{
    for (std::vector<std::string>::const_iterator it = content.begin();
                        it != content.end(); ++it)
    {
        _parseLine(*it);
    }
}

void	Database::_parseLine(const std::string& line)
{
    std::string date = line.substr(0, line.find("|"));
    float       value = _parseValue(line.substr(line.find("|") + 1));
   
    _dataBase.push_back(std::make_pair(Date(date), value));
}

float	Database::_parseValue(const std::string& valueStr)
{
    float	value = std::stof(valueStr);

    if (value < 0)
        throw std::runtime_error("Error: not a positive number.");
    if (value > 1000)
        throw std::runtime_error("Error: too large a number.");
    return (value);
}

///////////////////////////////////////////////////////////////////////////////

const std::vector<std::pair<Date, float>>&	Database::getDB() const
{
    return (_dataBase);
}

std::pair<Date, float>	Database::findClosestDate(const Date& date) const
{
    std::pair<Date, float>  closestDate = std::make_pair(Date("9999-12-31"), 0.0f);
    size_t                  span = SIZE_MAX;
    for (std::vector<std::pair<Date, float> >::const_iterator it = _dataBase.begin();
                        it != _dataBase.end(); ++it)
    {
        size_t currentSpan = date.getDaySpan(*it->first);
        if (currentSpan < span)
        {
            span = currentSpan;
            closestDate = *it;
        }
    }
    if (closestDate.first == Date("9999-12-31"))
        throw std::runtime_error("Error: no date found in database.");
    return (closestDate);
}

///////////////////////////////////////////////////////////////////////////////
/// BitcoinExchange
///////////////////////////////////////////////////////////////////////////////

BitcoinExchange::BitcoinExchange(const std::string& filename)
    : _file(filename), _db(_file.readFile())
{
}

BitcoinExchange::~BitcoinExchange()
{
}

void	BitcoinExchange::run()
{
    std::vector<std::pair<Date, float> >::const_iterator it = _db.getDB().begin();
    for (; it != _db.getDB().end(); ++it)
    {
        std::cout << it->first << " => " << it->second << " = " << "something" << std::endl;
    }
}
