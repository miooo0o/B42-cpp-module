#include "Base.hpp"

int main()
{

    for (int i = 0; i < 5; ++i)
    {
        std::cout << "=============================" << std::endl;
        std::cout << "Test " << i + 1 << ":" << std::endl;
        std::cout << "=============================" << std::endl;
        Base* base = generate(); 
        std::cout << "----------pointer------------" << std::endl;
        identify(base);
        std::cout << "---------reference-----------" << std::endl;
        identify(*base);
        delete base;
        std::cout << "\n\n" << std::endl;
    }

    std::cout << "=============================" << std::endl;
    std::cout << "Testing with a null pointer:" << std::endl;
    std::cout << "=============================" << std::endl;
    
    Base* nullBase = NULL;
    std::cout << "----------pointer------------" << std::endl;
    identify(nullBase);
    std::cout << "---------reference-----------" << std::endl;
    if (nullBase)
        identify(*nullBase);
    else
        std::cout << "Error: Cannot identify a null reference." << std::endl;
    return (0);
}