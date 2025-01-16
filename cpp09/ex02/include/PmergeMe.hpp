/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:27:59 by minakim           #+#    #+#             */
/*   Updated: 2025/01/16 13:09:58 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <deque>
#include <list>
#include <ctime>

// Base class
class ContainerBase
{
protected:
	std::pair<int, int>	firstStack;
	std::pair<int, int>	secondaryStack;
	bool				isOddElem;
	int					lastElem;
	std::time_t			startTime;
	std::time_t			endTime;

public:
	ContainerBase(const std::list<int>& arguments);
	virtual ~ContainerBase();

	virtual const std::list<int>	getSortedList() = 0;
	double							getExcutionDuration();
};

// List
class ListContainer : public ContainerBase
{
private:
	std::list<int>	data;

public:
	ListContainer(const std::list<int>& elements);
	~ListContainer();

	const std::list<int> getSortedList();
};

// Deque
class DequeContainer : public ContainerBase
{
private:
	std::deque<int> data;

public:
	DequeContainer(const std::list<int>& elements);
	~DequeContainer();

	const std::list<int> getSortedList();
};

class PmergeMe
{
private:
	ListContainer	listContainer;
	DequeContainer	dequeContainer;
public:
	PmergeMe(const std::list<int>& elements, const int count);
	~PmergeMe();

	void	compareExecutionTimes();
	void	compareResults();
	void	printResults();
};
