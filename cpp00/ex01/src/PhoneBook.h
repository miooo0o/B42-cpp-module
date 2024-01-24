#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.h"

/// library
# include <functional>
# include <limits>

/// Contacts as a list of 4 columns: index, first name, last name and nickname
/// Each column must be 10 characters wide
/// If the text is longer than the column, it must be truncated and
/// the last displayable character must be replaced by a dot (’.’)
/// If the index is out of range or wrong, define a relevant behavior.
/// Otherwise, display the contact information, one field per line

typedef bool (*f_isCondition)(const char c);

/// ADD: save a new contact
/// SEARCH: display a specific contact
/// EXIT

bool	isNumber(const char c);
bool	isPhoneNumber(const char c);
bool	StringSatisfied(const string& s, f_isCondition isCondition);

class PhoneBook {
public:
	PhoneBook();
	~PhoneBook();

	void	addContact(void);
	void	searchContact(void);

private:
	int		_count;
	Contact	_new_contact;
	Contact	_contacts[MAX_CONTACT];

	bool	tryCreateContact();
	bool	promptForField(const string& fieldName, t_Field field, f_isCondition isSatisfiedAll);
	void	increaseCount(void);
	int		getTargetIndex(void);
};

#endif
