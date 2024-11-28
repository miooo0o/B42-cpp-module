/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPNCalculator.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 23:12:13 by minakim           #+#    #+#             */
/*   Updated: 2024/11/29 00:26:45 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPNCalculator.hpp"

// default constructor, not used
RPNCalculator::RPNCalculator()
	: _operatorCount(0), _digitCount(0)
{}

// constructor
RPNCalculator::RPNCalculator(const std::string& expression)
	: _operatorCount(0), _digitCount(0)
{
	_parse(expression);
}

// destructor
RPNCalculator::~RPNCalculator()
{}

///////////////////////////////////////////////////////////////////////////////

int	RPNCalculator::calculate()
{
	if (_stack.size() != 1)
	{
		printLog();
		_printStackLog();
		throw std::runtime_error("invalid expression.");
	}
	return (_stack.top());
}

std::string	RPNCalculator::toString(int number)
{
	std::ostringstream	oss;
	oss << number;
	if (oss.fail() || oss.str().empty())
		throw std::runtime_error("failed to convert number to string.");
	return (oss.str());
}

///////////////////////////////////////////////////////////////////////////////

void	RPNCalculator::_parse(const std::string& expression)
{
	std::istringstream	iss(expression);
	std::string			token;

	while (iss >> token)
	{
		if (_isValid(token))
		{
			if (_isOperator(token))
			{
				if (_stack.size() < 2)
					throw std::runtime_error("not enough numbers to apply operator.");
				_executeOperator(token);
			}
			else
			{
				_digitCount++;
				_stack.push(_ttoi(token));
			}
		}
		else
		{
			printLog();
			throw std::invalid_argument(token + " is invalid token in expression.");
		}
	}
}

void	RPNCalculator::_executeOperator(const std::string& targetOperator)
{
	int	right = _stack.top();
	_stack.pop();
	int	left = _stack.top();
	_stack.pop();
	_applyOperator(targetOperator, left, right);
}

void	RPNCalculator::_applyOperator(const std::string& targetOperator, const int left, const int right)
{
	if (!_isOperator(targetOperator))
		throw std::invalid_argument("invalid operator.");
	_operatorCount++;
	if (targetOperator == "+")
		_stack.push(left + right);
	else if (targetOperator == "-")
		_stack.push(left - right);
	else if (targetOperator == "*")
		_stack.push(left * right);
	else if (targetOperator == "/")
	{
		if (right == 0)
		{
			_addLog(_createLog(targetOperator, left, right));
			printLog();
			throw std::runtime_error("can not division by zero.");
		}
		_stack.push(left / right);
	}

	_addLog(toString(left) + " " + targetOperator + " " + toString(right) + " = " + toString(_stack.top()));
}

void	RPNCalculator::_addLog(const std::string& msg)
{
	static int	index = 1;
	_log += "[" + toString(index++) + "] ";
	_log += msg + "\n";
}

std::string	RPNCalculator::_createLog(const std::string& targetOperator, const int left, const int right)
{
	std::string result;
	if (right == 0)
		result = "can not division by zero.";
	else
		result = _stack.top();
	return (toString(left) + " " + targetOperator + " " + toString(right) + " = " + result);
}

///////////////////////////////////////////////////////////////////////////////

bool	RPNCalculator::_isValid(const std::string& token)
{
	if (token.size() == 1 && _isOperator(token[0]))
		return (true);
	if (token.size() >= 1 && _isDigitToken(token))
	{
		try
        {
            _ttoi(token);
            return (true);
        }
        catch (const std::exception& e)
        {
			return (false);
        }
	}
	return (false);
}

bool	RPNCalculator::_isDigitToken(const std::string& token)
{
	for (size_t i = 0; i < token.size(); i++)
	{
		if (!isdigit(token[i]))
			return (false);
	}
	return (true);
}

bool	RPNCalculator::_isOperator(const std::string& op)
{
	return (op == "+" || op == "-" || op == "*" || op == "/");
}

bool	RPNCalculator::_isOperator(char op)
{
	return (op == '+' || op == '-' || op == '*' || op == '/');
}

int	RPNCalculator::_ttoi(const std::string& token)
{
	try
	{
		double	number = std::stod(token);
		if (number > INT_MAX || number < INT_MIN)
			throw std::overflow_error("number out of range.");
		return (static_cast<int>(number));
	}
	catch (const std::exception& e)
	{
		throw std::runtime_error(std::string("Invalid number: ") + e.what());
	}

}

///////////////////////////////////////////////////////////////////////////////
std::string	RPNCalculator::getLog() const
{
	return (_log);
}

void	RPNCalculator::printLog() const
{

	std::cout << "\n---------------------------------\n"
			  << "log"
			  << "\n---------------------------------" << std::endl;
	if (!_log.empty())
	{
		std::cout << "operator count: " << _operatorCount << std::endl;
		std::cout << "digit count: " << _digitCount << std::endl;
		if (_digitCount > 0 && _operatorCount > 0 && _digitCount != _operatorCount + 1)
		{
			if (_digitCount > _operatorCount + 1)
				std::cerr << "Too many numbers, missing operator(s).\n";
			else
	            std::cerr << "Too many operators, not enough numbers.\n";
		}
		std::cout << "\n---------------------------------\n"
			  << "process"
			  << "\n---------------------------------" << std::endl;
		std::cout << getLog() << std::endl;
	}
	else
		std::cout << "[ ] no log" << std::endl;
}


void	RPNCalculator::_printStackLog()
{
	std::cout << "\n---------------------------------\n"
			  << "stack"
			  << "\n---------------------------------" << std::endl;
	std::cout << "stack size: " << _stack.size() << std::endl;
	while (!_stack.empty())
	{
		std::cout << "[" << _stack.top() << "] ";
		_stack.pop();
	}
	std::cout << std::endl;
}