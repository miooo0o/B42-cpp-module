# pragma once

#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <sstream>

template <typename T>
class EasyFind
{
public:
	static int find(T& container, int value)
	{
		if (container.empty())
			throw std::runtime_error("Container is empty.");
		typename T::iterator it = std::find(container.begin(), container.end(), value);
		if (it == container.end())
		{
			std::ostringstream oss;
			oss << "Value not found: " << value;
			throw std::runtime_error(oss.str());
		}
		return (*it);
	}
};