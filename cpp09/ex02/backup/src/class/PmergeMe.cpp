/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:28:05 by minakim           #+#    #+#             */
/*   Updated: 2025/02/08 15:28:50 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "Validate.hpp"

////////////////////////////////////////////////////////////////////////////////
// Container Base
////////////////////////////////////////////////////////////////////////////////

ContainerBase::ContainerBase(const Validate& validated)
    : validatedList(validated.getList()), firstStack(), secondaryStack(), 
      isOddElem(validated.getList().size() % 2), lastElem(0), 
      startTime(0), endTime(0), isSorted(false)
{
    if (isOddElem)
    {
        lastElem = validatedList.front();
        validatedList.pop_front();   
    }
}

ContainerBase::ContainerBase(const ContainerBase& other)
    : validatedList(other.validatedList), firstStack(other.firstStack),
      secondaryStack(other.secondaryStack), isOddElem(other.isOddElem),
      lastElem(other.lastElem), startTime(other.startTime),
      endTime(other.endTime), isSorted(other.isSorted)
{
}

ContainerBase::~ContainerBase()
{
}

////////////////////////////////////////////////////////////////////////////////

bool    ContainerBase::getIsSorted() const
{
    return (getIsSorted);
}

std::string  ContainerBase::getExcutionDuration()
{
    if (!getIsSorted)
        throw std::runtime_error("sorting not completed, unable to retrieve duration.");
    if (!startTime || !endTime)
        throw std::runtime_error("start or end time not set, unable to calculate duration.");   
    
    std::ostringstream  oss;
    double              duration = std::difftime(endTime, startTime);
    if (duration <= 0.0)
        throw std::runtime_error("invalid duration: end time is earlier than or equal to start time");
    oss << (std::difftime(endTime, startTime) * 1000.0);
    if (!oss)
        throw  std::runtime_error("fail to convert to ostringstream ");
    oss << " ms";
    return (oss.str());
}

const std::list<int>    ContainerBase::getValidatedList() const
{
    return (validatedList);
}

////////////////////////////////////////////////////////////////////////////////
// List Container
////////////////////////////////////////////////////////////////////////////////

ListContainer::ListContainer(const ContainerBase& base)
    : ContainerBase(base), data(validatedList)
{
}

ListContainer::~ListContainer()
{
}

////////////////////////////////////////////////////////////////////////////////


void    ListContainer::sort()
{
    // TODO: Implement sorting logic
}

const std::list<int>    ListContainer::getSortedList()
{
    // TODO: Implement get sorted list
}

////////////////////////////////////////////////////////////////////////////////
// Deque Container
////////////////////////////////////////////////////////////////////////////////

DequeContainer::DequeContainer(const ContainerBase& base)
    : ContainerBase(base)
{
    convertDeque(base.getValidatedList());
}


DequeContainer::~DequeContainer()
{
}

void    DequeContainer::convertDeque(const std::list<int>& arguments)
{
    std::copy(arguments.begin(), arguments.end(), std::back_inserter(data));
}

////////////////////////////////////////////////////////////////////////////////


void    ListContainer::sort()
{
    // TODO: Implement sorting logic
}

const std::list<int>    ListContainer::getSortedList()
{
    // TODO: Implement get sorted list
}

////////////////////////////////////////////////////////////////////////////////
// PmergeMe
////////////////////////////////////////////////////////////////////////////////

PmergeMe::PmergeMe(const ContainerBase& base)
    : listContainer(base), dequeContainer(base)
{
}