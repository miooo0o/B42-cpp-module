#pragma once

#include <sstream>
#include <string>
#include <stdexcept>

class Utils
{
public:
	static int	stoi(std::string str)
	{
		std::istringstream	iss(str);
		int value;
        if (!(iss >> value))
            throw std::runtime_error("failed to convert string to int.");
        return (value);
	}

	static double	stod(std::string str)
	{
		std::istringstream	iss(str);
		double value;
        if (!(iss >> value))
            throw std::runtime_error("failed to convert string to int.");
        return (value);
	}

	static float	stof(std::string str)
	{
		std::istringstream	iss(str);
		float value;
        if (!(iss >> value))
            throw std::runtime_error("failed to convert string to int.");
        return (value);
	}
    
	static std::string to_string(int number)
	{
		std::ostringstream	oss;
		oss << number;
		if (oss.fail() || oss.str().empty())
			throw std::runtime_error("failed to convert number to string.");
		return (oss.str());
	}

	static std::string to_string(float number)
	{
		std::ostringstream	oss;
		oss << number;
		if (oss.fail() || oss.str().empty())
			throw std::runtime_error("failed to convert number to string.");
		return (oss.str());
	}
};