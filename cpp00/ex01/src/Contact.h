#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>

using namespace std;

/// @macro
# define MAX_CONTACT	8
# define FIELD_WIDTH	10
/// @enum
typedef enum e_Field {
	FirstName,
	LastName,
	NickName,
	PhoneNumber,
	DarkestSecret,
	InvalidField
}	t_Field;

/// It can store a maximum of 8 contacts.
/// If the user tries to add a 9th contact, replace the oldest one by the new one.
class Contact {
public:
	Contact();
	~Contact();

	bool	setField(t_Field field, const std::string& value);
	bool	setIndex(int index);

	void	printContact() const;
private:
	int		_index;
	string	_firstName;
	string	_lastName;
	string	_nickname;
	string	_phoneNumber;
	string	_darkestSecret;
};


#endif