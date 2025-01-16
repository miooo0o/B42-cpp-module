/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Validate.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:01:54 by minakim           #+#    #+#             */
/*   Updated: 2025/01/16 13:14:30 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <list>
#include <sstream>
#include <expected>
#include <limits.h>

class Validate
{
private:
	int             count;
	std::list<int>  elements;
	bool			isInitialized;

public:
	Validate(const int& argc, char** args);
	~Validate();

	bool    		isValidate() const;
	int				getCount();
	std::list<int>	getElements();

private:
	void			processArg(std::string& arg);
	std::string		trim(char* arg);
	bool			isNumber(std::string& str) const;
	bool			isInterger(std::string& str) const;
};
