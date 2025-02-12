#pragma once

#include <iostream>
#include <string>
#include <deque>
#include <list>
#include <ctime>
#include <sstream>
#include <algorithm>

////////////////////////////////////////////////////////////////////////////////

template <typename C, typename P>
class PmergeMe
{
private:
	typedef enum type {
		UNKNOWN = -1,
		DEQUE,
		LIST
	};
private:
	C						_data;
	std::time_t				_startTime;
	std::time_t				_endTime;

	bool					_isSorted;
	std::pair<bool, int>	_isOdd;
	static const Type		_type;


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
	bool		_baseCaseSort() const;
	P			_makePairs();
	void		_fordJohnsonSort();
	void		_spliteToWinnersLosers(P& pairs, C& winners, C& losers);
	void		_sortWinners(C& winners);
	
	void		_insertLosers(C& winners, C& losers);

};

// static init
template <typename C, typename P>
const typename PmergeMe<C, P>::Type PmergeMe<C, P>::_type =
	is_same<C, std::deque<int> >::value ? DEQUE :
	is_same<C, std::list<int> >::value ? LIST :
	UNKNOWN; 


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

