#include "ScalarConverter.hpp"
#include <iostream>
#include <vector>

int main()
{
    std::vector<std::string> testInputs;
    testInputs.push_back("42");           // Integer
    testInputs.push_back("-42");          // Negative integer
    testInputs.push_back("0");            // Zero
    testInputs.push_back("42.0f");        // Floating-point (float)
    testInputs.push_back("nan");          // NaN
    testInputs.push_back("nanf");         // NaN float
    testInputs.push_back("+inf");         // Positive infinity
    testInputs.push_back("-inf");         // Negative infinity
    testInputs.push_back("a");            // Character
    testInputs.push_back("127");          // Max char value
    testInputs.push_back("128");          // Out of char range
    testInputs.push_back("3.1415");       // Double type floating-point
    testInputs.push_back("1e10");         // Large double value
    testInputs.push_back("-3.40282e38");  // Near float minimum value
    testInputs.push_back("invalid");      // Invalid format
    testInputs.push_back("42..24");       // Invalid format
    testInputs.push_back("42.24ff");      // Invalid format
    testInputs.push_back("-inffff");      // Invalid format




    for (std::size_t i = 0; i < testInputs.size(); ++i)
    {
        std::cout << "=====================================" << std::endl;
        std::cout << "Testing input: \"" << testInputs[i] << "\"" << std::endl;
        std::cout << "-------------------------------------" << std::endl;
        
        ScalarConverter::convert(testInputs[i]);
        
        std::cout << "=====================================\n" << std::endl;
    }

    return 0;
}