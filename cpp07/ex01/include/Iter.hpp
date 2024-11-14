/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:17:10 by minakim           #+#    #+#             */
/*   Updated: 2024/11/14 16:17:12 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma

#include <stddef.h>
#include <iostream>

template <typename T>
void    iter(T *array, size_t size, void (*f)(T const &))
{
	for (size_t i = 0; i < size; i++)
		f(array[i]);
}

template <typename T>
void    print(T const &a)
{
	std::cout << a << std::endl;
	return ;
}

template <typename T>
size_t  arraySize(T const &array)
{
	return (sizeof(array) / sizeof(array[0]));
}