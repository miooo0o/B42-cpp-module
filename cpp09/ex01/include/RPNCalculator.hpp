#pragma once

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <stdexcept>

class RPNCalculator {
private:
	std::stack<int>	_stack;
	std::string		_log;
	int				_operatorCount;
	int				_digitCount;
public:
  	RPNCalculator(const std::string& expression);
    ~RPNCalculator();
	int					calculate();
	std::string			getLog() const;
	void				printLog() const;

	static std::string	toString(int number);

private:
    void                _parse(const std::string& expression);
	bool                _isOperator(const std::string& op);
	bool				_isOperator(char op);
    bool                _isValid(const std::string& line);
	void				_executeOperator(const std::string& targetOperator);
	void				_applyOperator(const std::string& targetOperator, const int left, const int right);
	int					_ttoi(const std::string& token);
	bool				_isDigitToken(const std::string& token);

	void				_addLog(const std::string& msg);
	std::string			_createLog(const std::string& targetOperator, const int left, const int right);
	void				_printStackLog();
	RPNCalculator();	// default, not used
};