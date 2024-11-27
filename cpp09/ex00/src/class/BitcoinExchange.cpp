/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:50:23 by minakim           #+#    #+#             */
/*   Updated: 2024/11/27 20:55:23 by minakim          ###   ########.fr       */
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
	if (_filename.empty())
		throw std::runtime_error("filename is empty.");
	if (_filename.find('.') == std::string::npos)
		throw std::runtime_error("filename has no extension.");
	if (_filename.find_last_of('.') != _filename.find_first_of('.'))
		throw std::runtime_error("filename has multiple extensions.");
	_extension = _filename.substr(_filename.find_last_of('.') + 1);
	openFile();
}

FileHandler::~FileHandler()
{
	closeFile();
}

///////////////////////////////////////////////////////////////////////////////

void	FileHandler::openFile()
{
	_file.open(_filename.c_str(), std::ios::in);
	if (!_file.is_open())
		throw std::runtime_error("could not open file " + _filename);
}

 std::vector<std::string>   FileHandler::readFile()
{
	std::vector<std::string> content;
	std::string line;

	while (std::getline(_file, line))
	{
		if (line.empty())
			continue;
		content.push_back(line);
	}
	if (content.empty())
		throw std::runtime_error("no content in file " + _filename);
	return (content);
}

void	FileHandler::closeFile()
{
	if (_file.is_open())
		_file.close();
}

std::string	FileHandler::getExtension() const
{
	return (_extension);
}

///////////////////////////////////////////////////////////////////////////////
/// DataBase
///////////////////////////////////////////////////////////////////////////////

Data::Data(const std::vector<std::string>& content)
	: _data(_initializeData(content))
{
}

Data::Data(const Data& other)
	: _data(other._data)
{}

Data::~Data()
{}


///////////////////////////////////////////////////////////////////////////////

std::multimap<Date, float> Data::_initializeData
                        (const std::vector<std::string>& content) const
{
	if (content.empty())
		throw std::runtime_error("no content in database file.");

	std::multimap<Date, float>	data;
	std::string					delimiter;

	std::vector<std::string>::const_iterator	it = content.begin();
	delimiter = _getDelimiter(*it);
	++it;

	for (; it != content.end(); ++it)
	{
	    std::pair<Date, float> parsedData = _parseLine(*it, delimiter);
	    data.insert(parsedData);
	}

	return (data);
}

std::string	Data::_getDelimiter(const std::string& line) const
{
	size_t i = 0;
	while (i < line.size() && (isalnum(line[i]) || line[i] == '_'))
        ++i;
    while (i < line.size() && isspace(line[i]))
        ++i;

    if (i < line.size() && !isalnum(line[i]) && isprint(line[i])) {

    	if (line[i] == '-')
    		throw std::runtime_error("invalid delimiter '-' in database file.");
        return (std::string(1, line[i]));
    }
	return ("");
}

std::pair<Date, float>	Data::_parseLine(const std::string& line, std::string& delimiter) const
{
	if (delimiter.empty())
		throw std::runtime_error("delimiter is empty.");
	if (line.size() < 10)
		throw std::runtime_error("date is less than 10 characters.");

	if (line.find_first_of(delimiter) == std::string::npos)
		return (std::make_pair(Date(line), std::numeric_limits<float>::quiet_NaN()));
	std::string date = line.substr(0, line.find(delimiter));
	std::string valueStr = line.substr(line.find(delimiter) + 1);
	if (date.empty())
		throw std::runtime_error("date is empty. " + date + " is not a valid date.");
	if (valueStr.empty())
		return (std::make_pair(Date(date), std::numeric_limits<float>::quiet_NaN()));
	float value = _parseValue(valueStr);
	return (std::make_pair(Date(date), value));
}

float	Data::_parseValue(const std::string& value) const
{
	try
	{
		return (std::stof(Date::trim(value)));
	}
	catch (const std::exception& e)
	{
		std::cerr << "parsing value: " << value << ", " << e.what() << std::endl;
		throw;
	}
}

///////////////////////////////////////////////////////////////////////////////

const std::multimap<Date, float>&    Data::getData() const
{
	return (_data);
}

Date	Data::findClosestDate(const Date& date) const
{
	if (_data.empty())
		throw std::runtime_error("no data in database.");
	if (!date.isValid())
        throw std::out_of_range("date is not valid.");
	if (_data.find(date) != _data.end())
		return (date);
	const std::multimap<Date, float>::const_iterator after = _data.lower_bound(date);
	std::multimap<Date, float>::const_iterator before;

	// if after is the first element, before is the end of the map
	// else, before is the element before after
	if (after == _data.begin()) 
		before = _data.end();
	else 
	{
		before = after;
		--before;
	}
	if (after == _data.end())
		return (before->first);
	if (before == _data.end())
		return (after->first);
	size_t	lowerSpan = date.getDaySpan(after->first);
	size_t	upperSpan = date.getDaySpan(before->first);
	return ((lowerSpan < upperSpan) ? after->first : before->first);
}

///////////////////////////////////////////////////////////////////////////////
/// BitcoinExchange
///////////////////////////////////////////////////////////////////////////////

BitcoinExchange::BitcoinExchange
				(const std::string& dbFilename, const std::string& bitcoinFilename)
	: _db(_createDataFromFile(dbFilename)),
      _bitcoin(_createDataFromFile(bitcoinFilename))
{
}

BitcoinExchange::BitcoinExchange
				(const Data& dateBase, const std::string& bitcoinFilename)
	: _db(dateBase),
      _bitcoin(_createDataFromFile(bitcoinFilename))
{
}

BitcoinExchange::~BitcoinExchange()
{
}

Data BitcoinExchange::_createDataFromFile(const std::string& filename)
{
    FileHandler fileHandler(filename);

    const std::vector<std::string> content = fileHandler.readFile();
    return (Data(content));
}

void	BitcoinExchange::run()
{
	std::cout << "Processing exchange..." << std::endl;
	if (_bitcoin.getData().empty())
		throw std::runtime_error("no data in bitcoin file.");
	if (_db.getData().empty())
		throw std::runtime_error("no data in database.");
	_processExchange();
}

void	BitcoinExchange::_processExchange()
{
	const std::multimap<Date, float>&	bitcoinData = _bitcoin.getData();
	const std::multimap<Date, float>&	dbData = _db.getData();

	for (std::multimap<Date, float>::const_iterator it = bitcoinData.begin(); it != bitcoinData.end(); ++it)
    {
        try
        {
            const Date&	currentDate		= it->first;
            const float	amountOfBitcoin = it->second;

        	if (std::isnan(amountOfBitcoin))
        		throw std::out_of_range("there is no exchange rate.");
            if (amountOfBitcoin <= 0)
                throw std::out_of_range("not a positive number.");
            if (amountOfBitcoin > 10000)
                throw std::out_of_range("too large a number.");

            Date	closestDate = _db.findClosestDate(currentDate);
            float	exchangeRate = dbData.find(closestDate)->second;
        	if (std::isnan(exchangeRate))
        		throw std::out_of_range("there is no exchange rate.");
            std::cout << currentDate << " => " << amountOfBitcoin << " = "
        		<< (exchangeRate * amountOfBitcoin) << std::endl;
        }
        catch (const std::out_of_range& e)
        {
            std::cerr << "Error: bad input => " << it->first << " : " << e.what() << std::endl;
        }
		catch (const std::invalid_argument& e)
		{
			std::cerr << "Error: bad input => " << it->first << " : " << e.what() << std::endl;
		}
    }
}
