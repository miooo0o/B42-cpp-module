# pragma once

#include <string>
#include <map>
#include <vector>
#include <tuple>
#include <iostream>
#include <fstream>


class Database
{
protected:
	std::vector<std::pair<Date, float> >	_dataBase;
private:
	std::ifstream								_file;
	const std::string							_filename;
public:
	Database(const std::string& filename);
	Database(const Database& other);
	Database& operator=(const Database& other);
	virtual ~Database();

	const std::vector<std::pair<Date, float>>&	getDB() const;
	std::pair<Date, float>						findClosestDate(const Date& date) const;

private:
	/// @brief default constructor, not used, private
	Database();

	void		_openFile();
	void		_closeFile();

	void   		_parse();
	void		_parseLine(const std::string& line);
	float		_parseValue(const std::string& value);

	bool		_isValidValue(float value);
};

class BitcoinExchange : public Database
{
public:
	BitcoinExchange(const std::string& filename);
	~BitcoinExchange();

	void	run();
};
