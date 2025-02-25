/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Validate.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:01:54 by minakim           #+#    #+#             */
/*   Updated: 2025/02/08 15:19:47 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <list>
#include <sstream>
#include <exception>
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

	bool			empty() const;
	bool			validated() const;

	// getter
	bool    				getValidated() const;
	int						getCount() const;
	const std::list<int>&	getList() const;

private:
	void			processArg(std::string& arg);
	std::string		trim(char* arg);
	bool			isNumber(std::string& str) const;
	bool			isInterger(std::string& str) const;
	bool			isUniqueNumber(const int num) const;

public: // test
	void			print();
};
