#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.h"
#include <functional>

/// Contacts as a list of 4 columns: index, first name, last name and nickname
/// Each column must be 10 characters wide
/// If the text is longer than the column, it must be truncated and
/// the last displayable character must be replaced by a dot (’.’)
/// If the index is out of range or wrong, define a relevant behavior.
/// Otherwise, display the contact information, one field per line

using namespace std;

typedef bool (*f_isString)(const string&);
typedef bool (*f_isCondition)(const char c);

/// ADD: save a new contact
/// SEARCH: display a specific contact
/// EXIT
class PhoneBook {
public:
	PhoneBook();
	~PhoneBook();

	void	addContact(void);
	void	searchContact(void);
	bool	tryCreateContact();
	// bool	promptForField(const std::string& fieldName, e_Field field);
	bool	promptForField(const string& fieldName, t_Field field, f_isCondition isCondition);
	void	increaseCount(void);

private:
	int		_count;
	Contact	_new_contact;
	Contact	_contacts[MAX_CONTACT];
};

#endif
