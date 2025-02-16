#pragma once

#include <iostream>
#include <sstream>
#include "PmergeMe.hpp" 

class Compare {
public:
    Compare(int ac, char** av)
    : listSorter(ac, av),
      dequeSorter(ac, av)
    {
    }

    void run()
	{

        std::cout << "Before: " << getString(listSorter.getData()) << std::endl;

        listSorter.sort();
        dequeSorter.sort();

        std::string s = getString(listSorter.getData());
        if (s == getString(dequeToList(dequeSorter.getData())))
            std::cout << "After : " << s << std::endl;
        else
            throw std::runtime_error("not same results");

        std::cout << "Time to process a range of " << listSorter.getData().size()
                  << " elements with std::list: " << listSorter.getExecutionDuration() << std::endl;
        std::cout << "Time to process a range of " << dequeSorter.getData().size()
                  << " elements with std::deque: " << dequeSorter.getExecutionDuration() << std::endl;
    }

    void muted_run()
    {
        if (!listSorter.getIsSorted())
        {
            listSorter.sort();
            dequeSorter.sort();
        }
        std::cout << "Time to process a range of " << listSorter.getData().size()
                  << " elements with std::list: " << listSorter.getExecutionDuration() << std::endl;
        std::cout << "Time to process a range of " << dequeSorter.getData().size()
                  << " elements with std::deque: " << dequeSorter.getExecutionDuration() << std::endl;
    }

private:

    PmergeMe<std::list<int>, std::list<std::pair<int, int> > >		listSorter;
    PmergeMe<std::deque<int>, std::deque<std::pair<int, int> > >	dequeSorter;


    template <typename Container>
    std::string getString(const Container& cont)
	{
         std::ostringstream oss;
        typename Container::const_iterator it = cont.begin();
        for (; it != cont.end(); ++it)
		{
            oss << *it << " ";
        }
        return (oss.str());
    }

    std::list<int> dequeToList(const std::deque<int>& deq)
	{
        return (std::list<int>(deq.begin(), deq.end()));
    }
};