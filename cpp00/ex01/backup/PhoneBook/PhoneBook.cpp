/// The program only accepts ADD, SEARCH and EXIT.
#include "PhoneBook.h"

PhoneBook::PhoneBook()	{ _count = 0; }
PhoneBook::~PhoneBook()	{}

bool	PhoneBook::promptForField(const std::string& fieldName, t_Field field)
{
	string		input;

	while (!std::cin.eof())
	{
		cout << "enter " << fieldName << ": ";
		getline(std::cin, input);
		if (cin.fail() || !input.empty() || !_new_contact.setField(field, input))
			return (false);
	}
	return (true);
}

bool	PhoneBook::tryCreateNewContact(void)
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
	if (tryCreateNewContact())
	{
		_contacts[_count % MAX_CONTACT] = _new_contact;
		increaseCount();
	}
	else
		cerr << "Contact creation failed." << endl;
}

void	searchContact(void)
{

}