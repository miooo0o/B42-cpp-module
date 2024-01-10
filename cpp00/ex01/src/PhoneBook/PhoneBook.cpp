/// The program only accepts ADD, SEARCH and EXIT.
#include "PhoneBook.h"

PhoneBook::PhoneBook()	{ _count(0); }
PhoneBook::~PhoneBook()	{}

bool	PhoneBook::promptForField(const std::string& fieldName, ContactField field)
{
	string		input;

	while (!std::cin.eof())
	{
		if (!_new_contact.setField(field, input))
			return (false);
		cout << "enter " << fieldName << ": ";
		getline(std::cin, input);
	}
	return (true);
}

bool	PhoneBook::tryCreateNewContact()
{
	return (_new_contact.setIndex(_count % MAX_CONTACT) &&
			promptForField("First name", FirstName) &&
			promptForField("Last name", LastName) &&
			promptForField("Nickname", NickName) &&
			promptForField("Phone number", PhoneNumber) &&
			promptForField("Darkest secret", DarkestSecret));
}

void	PhoneBook::addContact(void)
{
	if (tryCreateNewContact())
	{
		_contacts[_count % MAX_CONTACT] = _new_contact;
		_count++;
	}
	else
		cerr << "Contact creation failed." << endl;
}

void	searchContact(void)
{

}