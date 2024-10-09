/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:04:54 by minakim           #+#    #+#             */
/*   Updated: 2024/09/30 09:48:49 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <sstream>
#include <iostream>

int main()
{
	try
	{
		Bureaucrat  b1("b1", 3);
		AForm		f1("f1", 1, 1);

		b1.signForm(f1);
		f1.beSigned(b1);
		b1.signForm(f1);
		std::cout << f1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (1);
}