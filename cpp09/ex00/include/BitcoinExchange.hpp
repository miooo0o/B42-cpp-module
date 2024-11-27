# pragma once

#include <string>
#include <map>
#include <vector>
#include <tuple>
#include <iostream>
#include <fstream>

class Date;

class FileHandler
{
private:
	std::string					_filename;
	std::ifstream				_file;
	std::string					_extension;

public:
	FileHandler(const std::string& filename);
	~FileHandler();

	void						openFile();
	std::vector<std::string>	readFile();
	void						closeFile();
	std::string					getExtension() const;

};

class Data
{

private:
	const std::multimap<Date, float>	_data;

public:
	Data(const std::vector<std::string>& content);
	Data(const Data& other);
	~Data();

	const std::multimap<Date, float>&	getData() const;
	Date							findClosestDate(const Date& date) const;

private:
	/// @brief default constructor, not used, private
	Data();

	std::multimap<Date, float>		_initializeData(const std::vector<std::string>& content) const;
	std::pair<Date, float>		_parseLine(const std::string& line, std::string& delimiter) const;
	float						_parseValue(const std::string& value) const;
	std::string					_getDelimiter(const std::string& line) const;
};

class BitcoinExchange
{
private:
	Data	_db;
	Data	_bitcoin;

public:
	BitcoinExchange(const std::string& dbFilename, const std::string& bitcoinFilename);
	BitcoinExchange(const Data& dateBase, const std::string& bitcoinFilename);
	~BitcoinExchange();

	void	run();
private:
	/// @brief default constructor, not used, private
	BitcoinExchange();

	Data	_createDataFromFile(const std::string& filename);
	void	_processExchange();


};
