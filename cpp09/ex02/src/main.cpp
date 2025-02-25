#include "PmergeMe.hpp"
#include "Compare.hpp"

#include <vector>
int main(int ac, char** av)
{    
    try
    {
        Compare guriguri(ac, av);
        guriguri.run();
    }
    catch(const std::exception& e)
    {
        std::cerr << "error: " << e.what() << '\n';
    }
    
    // try
    // {
    //     PmergeMe<std::vector<int>, std::vector<std::pair<int, int> > > vecMe(ac, av);
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << "error: " << e.what() << '\n';
    // }

    return (0);
}