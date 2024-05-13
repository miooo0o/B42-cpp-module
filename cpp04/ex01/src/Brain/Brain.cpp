/// @file   Brain.cpp
/// @author minakim
/// @date   17-Mar-2024

#include "Brain.h"

/// @brief	constructor
Brain::Brain(void)
{
	announce("constructor called.");
}

Brain::Brain(const Brain &other)
{
	for (int i = 0; i < N_IDEAS; i++)
		_ideas[i] = other._ideas[i];
	announce("copy constructor called.");

}

/// @brief	destructor
Brain::~Brain(void)
{
	announce("destructor called.");
}

/// @brief	operator
Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i < N_IDEAS; i++)
			_ideas[i] = other._ideas[i];
	}
	return (*this);
}


/// @brief	public
void	Brain::set_idea(int index, std::string new_idea)
{
	_ideas[index] = new_idea;
}

std::string	Brain::get_idea(int index) const
{
	return (_ideas[index]);
}

/// @brief	private
void	Brain::announce(std::string const msg) const
{
	std::cout << "[ Brain ] " << msg << std::endl;
}
