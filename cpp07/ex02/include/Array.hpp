/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:16:58 by minakim           #+#    #+#             */
/*   Updated: 2024/11/14 16:45:17 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma

#include <cstddef>
#include <iostream>

template <typename T>
class Array {
public:
	Array();
	Array(const unsigned int& n);
	Array(const Array<T>& other);
	// Array<T>& operator=(const Array<T>& other);
	~Array();

	// size_t  size() const;

private:
	T*      _data;
	size_t  _size;
};


////////////////////////////////////////////////////////////////////////////////
/// constructor
////////////////////////////////////////////////////////////////////////////////

template <typename T>
Array<T>::Array()
	: _data(NULL), _size(0)
{
	std::cout << "Default array created" << std::endl;
}

template <typename T>
Array<T>::Array(const unsigned int& n)
	: _data(NULL), _size(n)
{
	if (_size <= 0)
	{
		_data = NULL;
		std::cout << "array: NULL" << " created" << std::endl;
	}
	else
	{
		_data = new T[n];
		for (unsigned int i = 0; i < n; i++)
		{
			_data[i] = T();
			std::cout << "array[" << i << "]: " << _data[i] << " created" << std::endl;
		}
	}
}

template <typename T>
Array<T>::Array(const Array<T>& other)
	: _data(NULL), _size(other._size)
{
   
}


////////////////////////////////////////////////////////////////////////////////
/// destructor
////////////////////////////////////////////////////////////////////////////////
template <typename T>
Array<T>::~Array()
{
	if (_data)
		delete[] _data;
	std::cout << "Array destroyed" << std::endl;
}