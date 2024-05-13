# include <iostream>
# include <string>
# include <cstdlib>

using	std::cout;
using	std::endl;
using	std::string;

int	main(void)
{
	string	s = "HI THIS IS BRAIN";
	string	*stringPTR = &s;
	string	&stringREF = s;
	
	cout << "[memory address]" << endl;
	cout << "memory address of the string variable:	" << &s << endl;
	cout << "memory address held by stringPTR:	" << stringPTR << endl;
	cout << "memory address held by stringREF:	" << &stringREF << endl << endl;

	cout << "[the value]" << endl;
	cout << "value of the string variable:	" << s << endl;
	cout << "value pointed to by stringPTR:	" << *stringPTR << endl;
	cout << "value pointed to by stringREF:	" << stringREF << endl;
	return (EXIT_SUCCESS);
}