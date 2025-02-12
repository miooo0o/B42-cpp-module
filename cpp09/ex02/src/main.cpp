#include "PmergeMe.hpp"

int main(int ac, char** av)
{    
    PmergeMe<std::list<int>, std::pair<int, int> >  listMe(ac, av);
    PmergeMe<std::deque<int>, std::pair<int, int> > dequeMe(ac, av);
    
    return (0);
}