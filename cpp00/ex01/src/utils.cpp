#include "PhoneBook.h"

bool	isNumber(const char c)
{
	return (isdigit(static_cast<const char>(c)) != 0);
}

bool	StringSatisfied(const string& s, f_isCondition isCondition)
{
	for (char c : s)
	{
		if (!isCondition(static_cast<const char>(c)))
			return (false);
	}
	return (true);
}

bool	isPhoneNumber(const char c)
{
	return ((isdigit(c) || c == '-' || c == '+' || isspace(c)) != 0);
}