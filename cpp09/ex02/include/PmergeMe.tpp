#include "PmergeMe.hpp"

template <typename C, typename P>
const typename PmergeMe<C, P>::Type PmergeMe<C, P>::_type =
	is_same<C, std::deque<int> >::value ? DEQUE :
	is_same<C, std::list<int> >::value ? LIST :
	UNKNOWN; 

template <typename C, typename P>
PmergeMe<C, P>::PmergeMe(int ac, char** av)
	: _isSorted(false), _isOdd(false, -1)
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
bool PmergeMe<C, P>::_baseCaseSort() const
{   
    int n = _date.size();
	if (n == 1)
    {
		_isSorted = true;
		return (true);
    }
    if (n == 2) // need more optimized
	{
		int first = _data.pop_front();
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
		int	first = _data.front();
		_data.pop_front();
        if (!_data.empty())
        {
            int	second = _data.front();
			_data.pop_front();
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
	if (_baseCaseSort(_data.size()))
    {
		_endTime = std::clock();
        return ;
    }
	_fordJohnsonSort();
}

template <typename C, typename P>
void PmergeMe<C, P>::_sortWinners(C& winners)
{
	switch (_type)
	{
	case DEQUE
	{
		std::sort(winners.begin(), winners.end());
		break;
	}
	case LIST
	{
		winners.sort();
		break;
	}
	default:
		throw std::runtime_error("unknown Type.");
	}
}
template <typename C, typename P>
void PmergeMe<C, P>::_spliteToWinnersLosers(P& pairs, C& winners, C& losers)
{
	typename P::iterator	pit;
	for (pit = pairs.begin(); pit != pairs.end(); ++pit)
		winners.push_back(pit->first);
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
}


template <typename C, typename P>
typename C::iterator	PmergeMe<C, P>::lower_bound(C& list, int value)
{
	
}

template <typename C, typename P>

void	PmergeMe<C, P>::_insertLosers(C& winners, C& losers)
{
	switch (_type)
	{
	case DEQUE
	{

		break;
	}
	case LIST
	{

		break;
	}
	default:
		throw std::runtime_error("unknown Type.");
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
