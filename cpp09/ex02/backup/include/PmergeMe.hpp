/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:27:59 by minakim           #+#    #+#             */
/*   Updated: 2025/02/08 15:28:58 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <deque>
#include <list>
#include <ctime>
#include <sstream>

// Base class
class ContainerBase
{
protected:
	std::list<int>		validatedList;
	std::pair<int, int>	firstStack;
	std::pair<int, int>	secondaryStack;
	bool				isOddElem;
	int					lastElem;
	std::time_t			startTime;
	std::time_t			endTime;
	bool				isSorted;


public:
	ContainerBase(const Validate& validated);
	ContainerBase(const ContainerBase& other);
	virtual ~ContainerBase();
	

	virtual void					sort() = 0;
	virtual const std::list<int>	getSortedList() = 0;
	
	bool							getIsSorted() const;
	std::string						getExcutionDuration();
	const std::list<int>			getValidatedList() const;

};

// List
class ListContainer : public ContainerBase
{
private:
	std::list<int>	data;

public:
	ListContainer(const ContainerBase& base);
	~ListContainer();

	void					sort(); // override
	const std::list<int>	getSortedList(); // override
};

// Deque
class DequeContainer : public ContainerBase
{
private:
	std::deque<int> data;

public:
	DequeContainer(const ContainerBase& base);
	~DequeContainer();

	void					sort(); // override
	const std::list<int>	getSortedList(); // override

private:
	void	convertDeque(const std::list<int>& arguments);
};

class PmergeMe
{
private:
	ListContainer	listContainer;
	DequeContainer	dequeContainer;
public:
	PmergeMe(const ContainerBase& base);
	~PmergeMe();

	void	compareExecutionTimes();
	void	compareResults();
	void	printResults();
};
