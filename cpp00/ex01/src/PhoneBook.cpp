#include "PhoneBook.h"

#include <limits>

PhoneBook::PhoneBook()	{ _count = 0; }
PhoneBook::~PhoneBook()	{}

bool	PhoneBook::_promptForField(const string& fieldName, t_Field field, f_isCondition isSatisfiedAll)
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
		if (!isSatisfiedAll)
			break ;
		if (StringSatisfied(input, isSatisfiedAll))
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

bool	PhoneBook::_tryCreateContact(void)
{
	return (_new_contact.setIndex(_count % MAX_CONTACT) &&
			_promptForField("First name", FirstName, nullptr) &&
			_promptForField("Last name", LastName, nullptr) &&
			_promptForField("Nickname", NickName, nullptr) &&
			_promptForField("Phone number", PhoneNumber, isPhoneNumber) &&
			_promptForField("Darkest secret", DarkestSecret, nullptr));
}

void	PhoneBook::_increaseCount(void) { _count += 1; }

void	PhoneBook::addContact(void)
{
	if (_tryCreateContact())
	{
		_contacts[_count % MAX_CONTACT] = _new_contact;
		_increaseCount();
		cout << "--- added to PhoneBook." << endl << endl;
	}
	else
		cerr << "--- contact creation failed. return to previous." << endl << endl;
}

bool	PhoneBook::_isValidIndex(string& input, int& index)
{
	std::istringstream	iss(input);

	if (!(iss >> index))
	{
		cerr << "--- the index [ " << input << " ] you entered is too large. please try again." << endl << endl;
		return (false);
	}
	if (index >= 1 && index <= MAX_CONTACT && index < _count + 1)
		return (true);
	else
	{
		cerr << "--- the index [ " << input << " ] you entered could not exited." << endl;
		cerr << "--- currently existing indexes: " << _count << " / 8" << endl;
		cerr << "--- return to previous." << endl << endl;
		return (false);
	}
}

int	PhoneBook::_getTargetIndex(void)
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
			if (_isValidIndex(input, index))
				return (index);
			continue ;
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
			cout << "--------------------------------------" << endl;
			break;
		}
		cout << "--------------- SEARCH ---------------" << endl;
		for (int i = 0; i < _count && i < MAX_CONTACT;  ++i)
			_contacts[i].displayOverview();
		cout << "--------------------------------------" << endl;
		inputIndex = _getTargetIndex() - 1;
		if (inputIndex < 0)
			continue ;
		_contacts[inputIndex].displayTarget();
		break ;
	}
}
