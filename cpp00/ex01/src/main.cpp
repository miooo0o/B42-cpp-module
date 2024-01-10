#include "PhoneBook.h"

int	main()
{
	PhoneBook	phonebook;
	string		cmd;

	cout << "welcome to the 80s and their unbelievable technology!" << endl
			<< "enter one of three options: ADD, SEARCH, EXIT"<< endl;
	while (true)
	{
		getline(cin, cmd);
		if (cin.eof())
			break ;
		if (cmd == "ADD")
			phonebook.addContact();
		else if (cmd == "SEARCH")
			phonebook.searchContact();
		else if (cmd == "EXIT")
			break ;
		else
			cerr << "warning! unrecognized command :" << cmd << endl
					<< "enter one of three options: ADD, SEARCH, EXIT" << endl;
	}
	std::cout << "EXIT" << std::endl;
	return (EXIT_SUCCESS);
}