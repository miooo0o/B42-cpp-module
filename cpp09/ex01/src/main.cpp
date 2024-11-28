/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 20:24:00 by minakim           #+#    #+#             */
/*   Updated: 2024/11/29 00:01:52 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPNCalculator.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <expression>" << std::endl;
		return (1);
	}
	try
	{
		RPNCalculator	calc(argv[1]);
		int             result = calc.calculate();

		std::cout << "result: " << result << std::endl;
		calc.printLog();

	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}
