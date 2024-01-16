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