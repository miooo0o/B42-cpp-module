#include "Contact.h"

#include <iomanip>

// init contact
Contact::Contact() : _index(0) {}
Contact::~Contact() {}


bool	Contact::setField(t_Field field, const string& value)
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


// |    |                  |                   |                     |
string	Contact::abbreviated(const string& field) const
{
	if (field.length() <= FIELD_WIDTH)
		return (field);
	else
		return (field.substr(0, FIELD_WIDTH - 3) + "...");
}

void	Contact::displayEachContact(const string& fieldName, int index) const
{


}