/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:17:05 by minakim           #+#    #+#             */
/*   Updated: 2024/11/14 16:17:06 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

int main(void)
{
	int		    intArray[] = {1, 2, 3, 4, 5};
	float	    floatArray[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
	double	    doubleArray[] = {1.11, 2.22, 3.33, 4.44, 5.55};
	std::string stringArray[] = {"happy", "dog", "guri", "so", "cute"};


	std::cout << "[int Array]" << std::endl;
	::iter(intArray, ::arraySize(intArray), ::print);
	std::cout << "\n" << std::endl;

	std::cout << "[float Array]" << std::endl;
	::iter(floatArray, ::arraySize(floatArray), ::print);
	std::cout << "\n" << std::endl;
	
	std::cout << "[double Array]" << std::endl;
	::iter(doubleArray, ::arraySize(doubleArray), ::print);
	std::cout << "\n" << std::endl;
	
	std::cout << "[string Array]" << std::endl;
	::iter(stringArray, ::arraySize(stringArray), ::print);
	std::cout << "\nsimple test done" << std::endl;

	return (0);
}