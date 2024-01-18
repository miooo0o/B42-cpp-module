#include "PhoneBook.h"

#include <limits>

PhoneBook::PhoneBook()	{ _count = 0; }
PhoneBook::~PhoneBook()	{}

bool	ignoreWhitespace()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return (true);
}

bool	isInputValid(const std::string& input)
{
	return (!cin.fail() || !input.empty());
}

bool	isNumber(const char c)
{
	return (isdigit(static_cast<const char>(c)) != 0);
}

bool	isString(const string& s, f_isCondition isCondition)
{
	for (char c : s)
	{
		if (!isCondition(static_cast<const char>(c)))
			return (false);
	}
	return (true);
}

bool	PhoneBook::promptForField(const string& fieldName, t_Field field, f_isCondition isCondition)
{
	string		input;

	while (true)
	{
		cout << "Enter " << fieldName << ": ";
		getline(cin, input);
		if (input.empty())
		{
			cerr << fieldName << " cannot be empty. Please try again." << endl;
			continue ;
		}
		if (isInputValid(input))
		{
			if (!isCondition)
				break ;
			if (isString(input, isCondition))
				break ;
		}
		cerr << "Invalid " << fieldName << ". Please try again." << endl;
		// ignoreWhitespace();
	}
	if (!_new_contact.setField(field, input))
	{
		cerr << "Failed to set field. Please try again." << endl;
		return (false);
	}
	return (true);
}

bool	PhoneBook::tryCreateContact(void)
{
	return (_new_contact.setIndex(_count % MAX_CONTACT) &&
			promptForField("First name", FirstName, nullptr) &&
			promptForField("Last name", LastName, nullptr) &&
			promptForField("Nickname", NickName, nullptr) &&
			promptForField("Phone number", PhoneNumber, isNumber) &&
			promptForField("Darkest secret", DarkestSecret, nullptr));
}

void	PhoneBook::increaseCount(void) { _count += 1; }

void	PhoneBook::addContact(void)
{
	if (tryCreateContact())
	{
		// test
		// _new_contact.printContact();
		_contacts[_count % MAX_CONTACT] = _new_contact;
		increaseCount();
		cout << "" << endl;
	}
	else
		cerr << "Contact creation failed." << endl;
}

void	()
{
	cout << "-------------------- CONTACTS --------------------" << endl;
}
