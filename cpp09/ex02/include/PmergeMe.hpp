#pragma once

#include <iostream>
#include <string>
#include <deque>
#include <list>
#include <ctime>
#include <sstream>
#include <algorithm>

////////////////////////////////////////////////////////////////////////////////

//  Template Metaprogramming
template <typename T, typename U>
struct is_same
{
	static const bool value = false;
};

template <typename T>
struct is_same<T, T>
{
	static const bool value = true;
};

template <bool Condition, typename T = void>
struct enable_if
{
};

template <typename T>
struct enable_if<true, T>
{
	typedef T type;
};

////////////////////////////////////////////////////////////////////////////////

template <typename C>
class PmergeMe
{
protected:
	C			_data;
	std::time_t	_startTime;
	std::time_t	_endTime;
	
	bool		_isSorted;

public:
	PmergeMe(int ac, char** av);
	virtual ~PmergeMe() {}

	void		sort();
	const C&	getSortedList() const;

	bool		getIsSorted() const { return _isSorted; }
	std::string	getExecutionDuration() const;

private:
	void		_validateAndStore(int ac, char** av);
	bool		_isNumber(const std::string& str) const;
	bool		_isInteger(std::string& str) const;
};

template <typename C>
PmergeMe<C>::PmergeMe(int ac, char** av) : _isSorted(false)
{
	_validateAndStore(ac, av);
}

template <typename C>
void PmergeMe<C>::_validateAndStore(int ac, char** av)
{
	if (ac <= 1)
		throw std::invalid_argument("error: at least one number is required.");

	for (int i = 1; i < ac; ++i)
	{
		std::string target(av[i]);
		if (!_isNumber(target) || !_isInteger(target))
			throw std::invalid_argument("error: invalid number [" + target + "]");

		int num = std::atoi(target.c_str());
		typename C::iterator it;
		for (it = _data.begin(); it != _data.end(); ++it)
		{
			if (*it == num)
				throw std::invalid_argument("error: duplicate number [" + target + "]");
		}
		_data.push_back(num);
	}
}

template <typename C>
bool PmergeMe<C>::_isNumber(const std::string& str) const
{
	size_t	i = 0;

	if (str[0] == '+')
		i++;
	if (str[0] == '-')
		throw std::invalid_argument("invalid input: negertive sign at [" + str + "]");
	for (; i < str.size(); ++i)
	{
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}
template <typename C>
bool	PmergeMe<C>::_isInteger(std::string& str) const
{
	std::istringstream	iss(str);
	double				stash;

	iss >> stash;
	if (stash > INT_MAX || stash < INT_MIN)
		throw std::invalid_argument("invalid input: number too large or small [" + str + "]");
	return (true);
}

/// @brief list
template <typename C>
void PmergeMe<C>::sort()
{
	typename enable_if<is_same<C, std::list<int> >::value>::type*   dummy = 0;

	_isSorted = true;
}

/// @brief deque
template <>
void PmergeMe<std::deque<int> >::sort()
{
	_isSorted = true;
}

template <typename C>
const C& PmergeMe<C>::getSortedList() const
{
	return _data;
}

template <typename C>
std::string PmergeMe<C>::getExecutionDuration() const
{
if (!getIsSorted)
		throw std::runtime_error("sorting not completed, unable to retrieve duration.");
	if (!_startTime || !_endTime)
		throw std::runtime_error("start or end time not set, unable to calculate duration.");   
	
	std::ostringstream  oss;
	double              duration = std::difftime(_endTime, _startTime);
	if (duration <= 0.0)
		throw std::runtime_error("invalid duration: end time is earlier than or equal to start time");
	oss << (std::difftime(_endTime, _startTime) * 1000.0);
	if (!oss)
		throw  std::runtime_error("fail to convert to ostringstream ");
	oss << " ms";
	return (oss.str());
}
