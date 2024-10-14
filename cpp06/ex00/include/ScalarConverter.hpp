/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 21:47:00 by minakim           #+#    #+#             */
/*   Updated: 2024/10/14 21:54:19 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include <limits>
#include <sstream>
#include <cstdlib>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <map>

class ScalarConverter
{
public:
    enum Type
    {
        CHAR,
        INT,
        FLOAT,
        DOUBLE,
        INVALID
    };
    static void convert(const std::string &input);

private:

    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ~ScalarConverter();
    ScalarConverter &operator=(const ScalarConverter &other);

    static Type detectType(const std::string& input);
    static bool isDouble(const std::string& input);
    static bool isInt(const std::string& input);
    static bool isFloat(const std::string& input);
    static bool isChar(const std::string& input);

    static void convertToChar(const std::string& input);
    static void convertToInt(const std::string& input);
    static void convertToFloat(const std::string& input);
    static void convertToDouble(const std::string& input);

    static void invalidInput(const std::string& msg);

    class ConversionFailException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
};