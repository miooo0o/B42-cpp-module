/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:50:23 by minakim           #+#    #+#             */
/*   Updated: 2024/11/21 13:02:10 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

///////////////////////////////////////////////////////////////////////////////
/// DataBase
///////////////////////////////////////////////////////////////////////////////

Database::Database(const std::string& filename)
    : _filename(filename)
{
	_openFile();
	_parse();
}

Database::Database(const Database& other)
    : _filename(other._filename)
{
	if (this != &other)
    {
        _dataBase = other._dataBase;
    }
}

Database& Database::operator=(const Database& other)
{
    if (this != &other)
        _dataBase = other._dataBase;
    return (*this);
}

Database::~Database()
{
    _closeFile();
}

