#ifndef PMERGEME_HPP
#define PMERGEME_HPP

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
	C						_data;
	std::time_t				_startTime;
	std::time_t				_endTime;

	bool					_isSorted;
	std::pair<bool, int>	_isOdd;
	std::string				_type;
public:
	PmergeMe(int ac, char** av);
	~PmergeMe() {}

	void		sort();

	bool		getIsSorted() const { return _isSorted; }
	std::string	getExecutionDuration() const;
	C			getData() const;

private:
	void		_validateAndStore(int ac, char** av);
	bool		_isNumber(const std::string& str) const;
	bool		_isInteger(std::string& str) const;
	bool		_isDuplicateNumber(int num) const;
	bool		_baseCaseSort();
	P			_makePairs();
	void		_fordJohnsonSort();
	void		_spliteToWinnersLosers(P& pairs, C& winners, C& losers);
	void		_sortWinners(C& winners);
	int			_getFrontData();
	
	void		_insertLosers(C& winners, C& losers);
	typename C::iterator	lower_bound(C& list, int value);

};

#include "PmergeMe.tpp"

#endif