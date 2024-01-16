#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>
#include <map>

using namespace std;

/// @macro
# define MAX_CONTACT	8

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
	
private:
	int		_index;
	string	_firstName;
	string	_lastName;
	string	_nickname;
	string	_phoneNumber;
	string	_darkestSecret;
};


#endif