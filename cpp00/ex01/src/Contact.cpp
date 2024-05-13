#include "Contact.h"

// init contact
Contact::Contact() : _index(0) {}
Contact::~Contact() {}


bool	Contact::setField(t_Field field, const std::string& value)
{
	switch (field)
	{
		case FirstName:
			_firstName = value;
			break;
		case LastName:
			_lastName = value;
			break;
		case NickName:
			_nickname = value;
			break;
		case PhoneNumber:
			_phoneNumber = value;
			break;
		case DarkestSecret:
			_darkestSecret = value;
			break;
		default:
			return (false);
	}
	return (true);
}

bool	Contact::setIndex(int index)
{
	if (index > MAX_CONTACT || index < 0)
		return (false);
	_index = index;
	return (true);
}

string	Contact::_abbreviated(const string& field) const
{
	if (field.length() <= FIELD_WIDTH)
		return (field);
	else
		return (field.substr(0, FIELD_WIDTH - 1) + ".");
}

void	Contact::displayOverview(void) const
{
	cout << "|" << std::setw(4) << std::left << _index + 1 << "|"
		 << std::setw(FIELD_WIDTH) << std::left << _abbreviated(_firstName) << "|"
		 << std::setw(FIELD_WIDTH) << std::left << _abbreviated(_lastName) << "|"
		 << std::setw(FIELD_WIDTH) << std::left << _abbreviated(_nickname) << "|"
		<< endl;
}

void	Contact::displayTarget(void) const
{
	cout << endl << "Index [ " << _index + 1 << " ]" << endl;
	cout << "First name: " << _firstName << endl;
	cout << "Last name: " << _lastName << endl;
	cout << "Nickname: " << _nickname << endl;
	cout << "Phone number: " << _phoneNumber << endl;
	cout << "Darkest secret: " << _darkestSecret << endl << endl;
}