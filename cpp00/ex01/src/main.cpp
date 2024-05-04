#include "PhoneBook.h"

void	showPrompt(void)
{
	cout << "> enter one of three options: ADD, SEARCH, EXIT"<< endl;
}

int	main()
{
	PhoneBook	phonebook;
	string		cmd;

	while (showPrompt(), getline(cin, cmd))
	{
		if (cmd == "ADD")
			phonebook.addContact();
		else if (cmd == "SEARCH")
			phonebook.searchContact();
		else if (cmd == "EXIT")
			break ;
		else
			cerr << "--- warning! unrecognized command: " << cmd << endl;
	}
	cout << "--- exit the program." << std::endl;
	return (EXIT_SUCCESS);
}