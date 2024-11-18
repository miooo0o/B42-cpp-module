#include "EasyFind.hpp"

int main()
{

    // set test cases
    int test_cases[] = {5, 11, 'a'};
    size_t test_count = sizeof(test_cases) / sizeof(test_cases[0]);

    std::cout << "\n1. vec\n" << std::endl;
    // set vector
    std::vector<int> vec;
    for (int i = 0; i < 10; i++)
        vec.push_back(i);
    // test    
    for (size_t i = 0; i < test_count; i++)
    {
        try
        {
            int value = EasyFind<std::vector<int> >::find(vec, test_cases[i]);
            std::cout << "Found value: " << value << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    std::cout << "\n2. list\n" << std::endl;
    // set list
    std::list<int> lst;
    for (int i = 0; i < 10; i++)
		lst.push_back(i);
    // test
    for (size_t i = 0; i < test_count; i++)
    {
        try
        {
            int value = EasyFind<std::list<int> >::find(lst, test_cases[i]);
            std::cout << "Found value: " << value << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << "\n  test done\n" << std::endl;
    return (0);
}