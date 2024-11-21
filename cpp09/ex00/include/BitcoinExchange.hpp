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
	const std::string						_filename;
	std::ifstream							_file;
public:
	FileHandler(const std::string& filename);
	~FileHandler();

	void						openFile();
	std::vector<std::string>	readFile();
	void						closeFile();
};

class Database
{
private:
	std::vector<std::pair<Date, float> >	_dataBase;

public:
	Database(const std::vector<std::string>& content);
	Database(const Database& other);
	Database& operator=(const Database& other);
	~Database();

	const std::vector<std::pair<Date, float>>&	getDB() const;
	std::pair<Date, float>						findClosestDate(const Date& date) const;

private:
	/// @brief default constructor, not used, private
	Database();

	void   		_parse(const std::vector<std::string>& content);
	void		_parseLine(const std::string& line);
	float		_parseValue(const std::string& value);
	bool		_isValidValue(float value);
};

class BitcoinExchange
{
public:
	BitcoinExchange(const std::string& filename);
	~BitcoinExchange();

	void	run();
	void	printDB();


private:
	Database	_db;
	FileHandler	_file;
};
