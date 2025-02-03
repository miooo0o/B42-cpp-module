/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:28:05 by minakim           #+#    #+#             */
/*   Updated: 2025/02/03 16:36:16 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

////////////////////////////////////////////////////////////////////////////////
// Container Base
////////////////////////////////////////////////////////////////////////////////

ContainerBase::ContainerBase(const std::list<int>& arguments)
    : validated(arguments), isOddElem(arguments.size() % 2)
{
    if (isOddElem)
    {
        lastElem = ;
        validated.pop_front();   
    }
}

ContainerBase::~ContainerBase()
{
}

////////////////////////////////////////////////////////////////////////////////
// List Container
////////////////////////////////////////////////////////////////////////////////

ListContainer::ListContainer(const std::list<int>& arguments)
    : ContainerBase(arguments), data(validated)
{
}

ListContainer::~ListContainer()
{
}

////////////////////////////////////////////////////////////////////////////////
// Deque Container
////////////////////////////////////////////////////////////////////////////////

DequeContainer::DequeContainer(const std::list<int>& arguments)
    : ContainerBase(arguments)
{
    convertDeque(arguments);
}


DequeContainer::~DequeContainer()
{
}

////////////////////////////////////////////////////////////////////////////////
// PmergeMe
////////////////////////////////////////////////////////////////////////////////

PmergeMe::PmergeMe(const std::list<int>& elements)
    : listContainer(elements), dequeContainer(elements)
{

}