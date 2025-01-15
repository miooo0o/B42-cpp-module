/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Validate.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:01:54 by minakim           #+#    #+#             */
/*   Updated: 2025/01/15 16:32:23 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <list>
#include <sstream>
#include <expected>

class Validate
{
private:
	int             count;
	std::list<int>  elements;
	bool			isInitialized;
public:
	Validate(const int& argc, char** args);
	~Validate();

	bool    	isValidate() const;
private:
	void		processArg(std::string& arg);
	std::string	trim(char* arg);
	bool		isNumber(std::string& str) const;

	void    	setCount();
	void		setElements();
};
