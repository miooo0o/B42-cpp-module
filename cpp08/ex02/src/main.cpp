#include "MutantStack.hpp"
#include <list>
int main()
{
    // MutantStack
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << "MutantStack top: " << mstack.top() << std::endl;
        mstack.pop();
        std::cout << "MutantStack size: " << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        std::cout << "MutantStack elements: ";
        while (it != ite)
        {
            std::cout << *it << " ";
            ++it;
        }
        std::cout << std::endl;
    }

    // std::list
    {
        std::list<int> lst;
        lst.push_back(5);
        lst.push_back(17);
        std::cout << "List top: " << lst.back() << std::endl;
        lst.pop_back();
        std::cout << "List size: " << lst.size() << std::endl;
        lst.push_back(3);
        lst.push_back(5);
        lst.push_back(737);
        lst.push_back(0);

        std::list<int>::iterator it = lst.begin();
        std::list<int>::iterator ite = lst.end();
        ++it;
        --it;
        std::cout << "List elements: ";
        while (it != ite)
        {
            std::cout << *it << " ";
            ++it;
        }
        std::cout << std::endl;
    }

    return (0);
}