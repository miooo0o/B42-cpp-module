#include "Base.hpp"

Base*   generate(void)
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    int type = rand() % 3;

    switch (type)
    {
    case 0:
        std::cout << "Generated an instance of Type A." << std::endl;
        return new A;
    case 1:
        std::cout << "Generated an instance of Type B." << std::endl;
        return new B;
    case 2:
        std::cout << "Generated an instance of Type C." << std::endl;
        return new C;
    default:
        std::cerr << "Error: Unknown type, failed to generate an instance." << std::endl;
        return NULL;
    }

}

void    identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Base pointer identified: Type A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Base pointer identified: Type B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Base pointer identified: Type C" << std::endl;
    else
        std::cout << "Unknown type or null pointer provided." << std::endl;
}

void    identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "Reference identified: Type A" << std::endl;
    }
    catch (std::bad_cast&)
    {
        std::cerr << "Error: Reference is not of type A" << std::endl;
    }
    
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "Reference identified: Type B" << std::endl;
    }
    catch (std::bad_cast&)
    {
        std::cerr << "Error: Reference is not of type B" << std::endl;
    }

    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "Reference identified: Type C" << std::endl;
    }
    catch (std::bad_cast&)
    {
        std::cerr << "Error: Reference is not of type C" << std::endl;
    }
}