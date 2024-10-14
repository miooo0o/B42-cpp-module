/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:58:45 by minakim           #+#    #+#             */
/*   Updated: 2024/10/14 17:19:38 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class Form
{
private:
	const std::string   _name;
	bool				_isSigned;
	const int			_minSignGrade;
	const int			_minExecGrade;
protected:
	/// @brief  beExecute is a pure virtual function
	virtual void	beExecute(const Bureaucrat& executor) const = 0;
public:
	Form();
	Form(std::string name, const int minSignGrade, const int minExecGrade);

	/// @brief  Form destructor is virtual
	virtual ~Form();

	Form(Form const &other);
	Form& operator=(const Form &other);
	
	void		execute(const Bureaucrat& executor) const;
	void		beSigned(Bureaucrat &bureaucrat);
	
	int			getMinSignGrade() const;
	int 		getMinExecGrade() const;
	std::string	getName() const;
	bool		getIsSigned() const;
	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};

	class FormNotSignedException : public std::exception
	{
		virtual const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, Form const &form);
