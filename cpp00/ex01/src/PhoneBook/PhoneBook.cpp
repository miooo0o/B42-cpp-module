#include "PhoneBook.h"

#include <limits>

PhoneBook::PhoneBook()	{ _count = 0; }
PhoneBook::~PhoneBook()	{}


void	printError(const std::string& msg)
{
	cerr << msg << endl;
}

bool	clearIgnore()
{
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return (true);
}

bool	isInputValid(const std::string& input)
{
	return (!cin.fail() || !input.empty());
}

bool	PhoneBook::promptForField(const std::string& fieldName, t_Field field)
{
	string		input;

	while (true)
	{
		cout << "Enter " << fieldName << ": ";
		getline(cin, input);
		if (isInputValid(input))
			break;
		printError("Invalid input. Please try again.");
		clearIgnore();
	}
	if (!_new_contact.setField(field, input))
	{
		printError("Failed to set field. Please try again.");
		return (false);
	}
	return (true);
}

bool	PhoneBook::tryCreateContact(void)
{
	return (_new_contact.setIndex(_count % MAX_CONTACT) &&
			promptForField("First name", FirstName) &&
			promptForField("Last name", LastName) &&
			promptForField("Nickname", NickName) &&
			promptForField("Phone number", PhoneNumber) &&
			promptForField("Darkest secret", DarkestSecret));
}

void	PhoneBook::increaseCount(void) { _count += 1; }

void	PhoneBook::addContact(void)
{
	if (tryCreateContact())
	{
		_contacts[_count % MAX_CONTACT] = _new_contact;
		increaseCount();
	}
	else
		printError("Contact creation failed.");
}
