/// In your code, the phonebook must be instantiated as an instance of the PhoneBook class.
/// Same thing for the contacts.
/// Each of them must be instantiated as an instance of the Contact class.
/// You’re free to design the classes as you like but keep in mind that anything
/// that will always be used inside a class is private,
/// and anything that can be used outside a class is public

#include "Contact.h"

Contact::Contact() { _index = 0; }
Contact::~Contact() {}

bool	setIndex(const int index);
bool	setField(t_Field const field, const string input);


bool	Contact::setIndex(const int index)
{
	if (index) // bigger than MAX_INDEX
		return (false);
	this->_index = index;
	return (true);
}

bool	setField(t_Field const field, const string input)
{
	if (input.empty())
		cerr << "empty ... " << endl;
	switch (field)
	{
		case FirstName:
		{
		
		}
		case LastName:
		{
		
		}
		default:
		{
		
		}
	}
}