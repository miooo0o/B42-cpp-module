/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:19:36 by minakim           #+#    #+#             */
/*   Updated: 2024/11/21 11:29:52 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() : std::stack<T>() {}
	MutantStack(const MutantStack& other) : std::stack<T>(other) {}
	~MutantStack() {};
	MutantStack& operator=(const MutantStack& other);
	
	typedef typename std::stack<T>::container_type::iterator                iterator;
	typedef typename std::stack<T>::container_type::const_iterator          const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator        reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator  const_reverse_iterator;

	// iterators
	iterator                begin();
	iterator                end();
	// const iterators
	const_iterator          begin() const;
	const_iterator          end() const;
	// reverse iterators
	reverse_iterator        rbegin();
	reverse_iterator        rend();
	// const reverse iterators
	const_reverse_iterator  rbegin() const;
	const_reverse_iterator  rend() const;
};

////////////////////////////////////////////////////////////////////////////////////
/// assignment operator
////////////////////////////////////////////////////////////////////////////////////

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& other)
{
    if (this != &other)
	{
        std::stack<T>::operator=(other);
    }
    return (*this);
}

////////////////////////////////////////////////////////////////////////////////////
/// begin
////////////////////////////////////////////////////////////////////////////////////

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (this->c.begin());
}
template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
	return (this->c.rbegin());
}
template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const
{
	return (this->c.rbegin());
}


////////////////////////////////////////////////////////////////////////////////////
/// end
////////////////////////////////////////////////////////////////////////////////////

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
	return (this->c.rend());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const
{
	return (this->c.rend());
}
