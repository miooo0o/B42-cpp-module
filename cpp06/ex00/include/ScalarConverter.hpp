/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 21:47:00 by minakim           #+#    #+#             */
/*   Updated: 2024/10/26 14:30:12 by minakim          ###   ########.fr       */
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
    static void convert(const std::string &input);

private:

    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ~ScalarConverter();
    ScalarConverter &operator=(const ScalarConverter &other);


    static void convertToChar(double value);
    static void convertToInt(double value);
    static void convertToFloat(double value);
    static void convertToDouble(double value);

    static double parseInput(const std::string& input);
    static std::string	checkFormatting(const std::string& input);

};