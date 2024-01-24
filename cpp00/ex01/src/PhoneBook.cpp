#include "PhoneBook.h"

#include <limits>

PhoneBook::PhoneBook()	{ _count = 0; }
PhoneBook::~PhoneBook()	{}

bool	PhoneBook::promptForField(const string& fieldName, t_Field field, f_isCondition isCondition)
{
	string		input;

	while (true)
	{
		cout << "> enter " << fieldName << ": ";
		getline(cin, input);
		if (input.empty())
		{
			cerr << "--- "<< fieldName << "cannot be empty. Please try again." << endl << endl;
			continue ;
		}
		if (!isCondition)
			break ;
		if (StringSatisfied(input, isCondition))
			break ;
		cerr << "--- invalid " << fieldName << ". please try again." << endl << endl;
	}
	if (!_new_contact.setField(field, input))
	{
		cerr << "--- failed to set field. Please try again." << endl << endl;
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
			promptForField("Phone number", PhoneNumber, isPhoneNumber) &&
			promptForField("Darkest secret", DarkestSecret, nullptr));
}

void	PhoneBook::increaseCount(void) { _count += 1; }

void	PhoneBook::addContact(void)
{
	if (tryCreateContact())
	{
		_contacts[_count % MAX_CONTACT] = _new_contact;
		increaseCount();
		cout << "--- added to PhoneBook." << endl << endl;
	}
	else
		cerr << "--- contact creation failed. return to previous." << endl << endl;
}

int	PhoneBook::getTargetIndex(void)
{
	string		input;
	int			index;

	while (true)
	{
		cout << "> enter the index of the contact you want to view: ";
		getline(cin, input);
		if (input.empty())
		{
			cerr << "--- cannot be empty. please try again." << endl << endl;
			continue ;
		}
		if (StringSatisfied(input, isNumber))
		{
			index = stoi(input);
			if (index >= 1 && index <= MAX_CONTACT && index < _count + 1)
				return (index);
			else
			{
				cerr << "--- the index [ " << input << " ] you entered could not exited." << endl;
				cerr << "--- currently existing indexes: " << _count << " / 8" << endl;
				cerr << "--- return to previous." << endl << endl;
				return (false);
			}
		}
		cerr << "--- index can be a number only. please try again." << endl << endl;
	}
}

void	PhoneBook::searchContact(void)
{
	int	inputIndex;
	
	while (true)
	{
		// add condition : if there is no index
		if (_count == 0)
		{
			cout << "--------------- SEARCH ---------------" << endl;
			cout << "    your phonebook is empty." << endl;
			cout << "--- return to previous." << endl;
			break;
		}
		cout << "--------------- SEARCH ---------------" << endl;
		for (int i = 0; i < _count && i < MAX_CONTACT;  ++i)
			_contacts[i].displayOverview();
		inputIndex = getTargetIndex() - 1;
		if (inputIndex < 0)
			continue ;
		_contacts[inputIndex].displayTarget();
		break ;
	}
}
