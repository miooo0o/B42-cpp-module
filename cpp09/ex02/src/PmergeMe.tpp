#include "PmergeMe.hpp"

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
PmergeMe<C, P>::PmergeMe(int ac, char** av)
	: _isSorted(false), _isOdd(false, -1)
{
	if (!(is_same<C, std::list<int> >::value || is_same<C, std::deque<int> >::value))
		throw std::runtime_error("unknown type. only support: list, deque");
	if (is_same<C, std::list<int> >::value)
		_type = "list";
	else if (is_same<C, std::deque<int> >::value)
		_type = "deque";
	// std::cout << "correct container [" << _type << "] assigned . . ." << std::endl;
	_validateAndStore(ac, av);
	// std::cout << "[" << _type << "] validated . . ." << std::endl;
}


template <typename C, typename P>
bool	PmergeMe<C, P>::_isDuplicateNumber(int num) const
{
	typename C::const_iterator it = _data.begin();
	while (it != _data.end())
	{
		if (*it == num)
			return (true);
		it++;
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
int	PmergeMe<C, P>::_getFrontData()
{
	int res = _data.front();
	_data.pop_front();
	return (res);
}

template <typename C, typename P>
bool PmergeMe<C, P>::_baseCaseSort()
{   
    int n = _data.size();
	if (n == 1)
    {
		_isSorted = true;
		return (true);
    }
    if (n == 2) // need more optimized
	{
		int	first = _getFrontData();
		if (_data.front() > first)
			_data.push_front(first);
		else
			_data.push_back(first);
		_isSorted = true;
		return (true);
	}
	return (false);
}

template <typename C, typename P>
P	PmergeMe<C, P>::_makePairs()
{
	P						pairs;
	typename C::iterator	it = _data.begin();
	while (!_data.empty())
	{
		int	first = _getFrontData();
        if (!_data.empty())
        {
            int	second = _getFrontData();
            if (first < second)			   // (larger, smaller)
				pairs.push_back(std::make_pair(second, first));
            else
				pairs.push_back(std::make_pair(first, second));
		}
		else
		{
			_isOdd.first = true;
			_isOdd.second = first;
		}
	}
	return (pairs);
}

template <typename C, typename P>
void	PmergeMe<C, P>::sort()
{
	_startTime = std::clock();
	if (_baseCaseSort())
    {
		_endTime = std::clock();
        return ;
    }
	_fordJohnsonSort();
	_endTime = std::clock();
    return ;
}

template <typename C, typename P>
void PmergeMe<C, P>::_spliteToWinnersLosers(P& pairs, C& winners, C& losers)
{
	typename P::iterator	pit;
	for (pit = pairs.begin(); pit != pairs.end(); ++pit)
	{
		winners.push_back(pit->first);
		losers.push_back(pit->second);
	}
	if (_isOdd.first)
		winners.push_back(_isOdd.second);
}

template <typename C, typename P>
void	PmergeMe<C, P>::_fordJohnsonSort()
{
	C	winners;
	C	losers;
	// 1. make pairs
	P	pairs = _makePairs();
	// 2. split pairs and store to winners/losers
	_spliteToWinnersLosers(pairs, winners, losers);
	// 3. sort winners
	_sortWinners(winners);
	// 4. insert losers Jocobsthal number (find logic: std::lower_bound)
	_insertLosers(winners, losers);

	_data = winners;
	_isSorted = true;
}


template <typename C, typename P>
typename C::iterator	PmergeMe<C, P>::lower_bound(C& list, int value)
{
	typename C::iterator	left	= list.begin();
	typename C::iterator	right	= list.end();
	int						size	= std::distance(left, right);

	while (size > 0)
	{
		typename C::iterator	mid = left;
		std::advance(mid, size / 2);
		if (*mid < value)
		{
            left = mid;
            ++left;
            size = size - (size / 2) - 1;
        }
		else
		{
            right = mid;
            size /= 2;
        }
    }
    return (right);
}

template <typename Iterator>
Iterator it_next(Iterator it, int n = 1)
{
    std::advance(it, n);
    return it;
}

////////////////////////////////////////////////////////////////////////////////


template <typename C, typename P>
void PmergeMe<C, P>::_sortWinners(C& winners)
{
    throw std::runtime_error("unknown Type.");
}

template <>
void PmergeMe<std::list<int>, std::list<std::pair<int, int> > >::_sortWinners(std::list<int>& winners)
{
    winners.sort();
}

template <>
void PmergeMe<std::deque<int>, std::deque<std::pair<int, int> > >::_sortWinners(std::deque<int>& winners)
{
    std::sort(winners.begin(), winners.end());
}

template <typename C, typename P>
void PmergeMe<C, P>::_insertLosers(C& winners, C& losers)
{
	throw std::runtime_error("unknown Type.");
}

template <>
void PmergeMe<std::list<int>, std::list<std::pair<int, int> > >::_insertLosers(std::list<int>& winners, std::list<int>& losers)
{
	std::list<int>::iterator los_it = losers.begin();
    while (los_it != losers.end())
	{
    	std::list<int>::iterator pos = lower_bound(winners, *los_it);
        std::list<int>::iterator next_it = it_next(los_it);
        winners.splice(pos, losers, los_it);
        los_it = next_it;
    }
}

template <>
void PmergeMe<std::deque<int>, std::deque<std::pair<int, int> > >::_insertLosers(std::deque<int>& winners, std::deque<int>& losers)
{
	std::deque<int>::iterator los_it = losers.begin();
    while (los_it != losers.end())
	{
        std::deque<int>::iterator pos = std::lower_bound(winners.begin(), winners.end(), *los_it);
        winners.insert(pos, *los_it);
        ++los_it;
    }
}

////////////////////////////////////////////////////////////////////////////////

template <typename C, typename P>
std::string PmergeMe<C, P>::getExecutionDuration() const
{
if (!getIsSorted())
		throw std::runtime_error("sorting not completed, unable to retrieve duration.");
	if (!_startTime || !_endTime)
		throw std::runtime_error("start or end time not set, unable to calculate duration.");   
	
	std::ostringstream  oss;
	double              duration = (_endTime - _startTime) * 1000.0 / CLOCKS_PER_SEC;
	if (duration <= 0.0)
		throw std::runtime_error("invalid duration: end time is earlier than or equal to start time");
	oss << (duration);
	if (!oss)
		throw  std::runtime_error("fail to convert to ostringstream ");
	oss << " ms";
	return (oss.str());
}

template <typename C, typename P>
C	PmergeMe<C, P>::getData() const
{
	return (_data);
}