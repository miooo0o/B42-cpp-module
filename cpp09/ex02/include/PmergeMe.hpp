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

template <typename C, typename P>
class PmergeMe
{
protected:
	C			_data;
	std::time_t	_startTime;
	std::time_t	_endTime;
	
	bool		_isSorted;

public:
	PmergeMe(int ac, char** av);
	~PmergeMe() {}

	void		sort();
	const C&	getData() const;

	bool		getIsSorted() const { return _isSorted; }
	std::string	getExecutionDuration() const;

private:
	void		_validateAndStore(int ac, char** av);
	bool		_isNumber(const std::string& str) const;
	bool		_isInteger(std::string& str) const;
	bool		_isDuplicateNumber(int num) const;
	bool		_baseCase(size_t n)
};

template <typename C, typename P>
PmergeMe<C, P>::PmergeMe(int ac, char** av)
	: _isSorted(false)
{
	_validateAndStore(ac, av);
}

template <typename C, typename P>
bool	PmergeMe<C, P>::_isDuplicateNumber(int num) const
{
	typename C::iterator it;
	for (it = _data.begin(); it != _data.end(); ++it)
	{
		if (*it == num)
			return (true);
	}
	return (false);
}

template <typename C, typename P>
void	PmergeMe<C, P>::_validateAndStore(int ac, char** av)
{
	if (ac <= 1)
		throw std::invalid_argument("error: at least one number is required.");

	for (int i = 1; i < ac; ++i)
	{
		std::string	target(av[i]);
		if (!_isNumber(target))
			throw std::invalid_argument("error: invalid input [" + target + "]: not a number");
		if (!_isInteger(target))
			throw std::invalid_argument("error: invalid input [" + target + "]: not integer");
		int num = std::atoi(target.c_str());
		if (!_isDuplicateNumber(num))
			_data.push_back(num);
	}
}

template <typename C, typename P>
bool PmergeMe<C, P>::_isNumber(const std::string& str) const
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

template <typename C, typename P>
bool	PmergeMe<C, P>::_isInteger(std::string& str) const
{
	std::istringstream	iss(str);
	double				stash;

	iss >> stash;
	if (stash > INT_MAX || stash < INT_MIN)
		throw std::invalid_argument("invalid input: number too large or small [" + str + "]");
	return (true);
}


template <typename C, typename P>
bool PmergeMe<C, P>::_baseCase(size_t n)
{
	if (n == 2)
	{
		// if [0] > [1], swap;
		_endTime = std::clock(); // std::time(NULL)
		_isSorted = true;
		return (true);
	}
	return (false);
}

template <typename C, typename P>
void	PmergeMe<C, P>::sort()
{

	bool	isDeque = is_same<C, std::deque<int> >::value;
	_startTime = std::clock();
	if (_baseCase(_data.size()))
		_endTime = std::clock(); return ;

	typename P				pairs;
	typename C::iterator	it = _data.begin();
	while (it != _date.end())
	{
		int first = *it;
		++it;
	}

}

template <typename C, typename P>
const C& PmergeMe<C, P>::getData() const
{
	return (_data);
}

template <typename C, typename P>
std::string PmergeMe<C, P>::getExecutionDuration() const
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
