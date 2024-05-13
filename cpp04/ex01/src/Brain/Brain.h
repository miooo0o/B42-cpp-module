/// @file   Brain.h
/// @author minakim
/// @date   17-Mar-2024

#ifndef Brain_H
#define Brain_H

/// @library
#include <iostream>

/// @macro
#define N_IDEAS	100

/// @class Brain
class Brain {
public:
	Brain(void);
	Brain(const Brain &other);
	~Brain(void);
	
	Brain	&operator=(const Brain &other);
	
	void		set_idea(int index, std::string new_idea);
	std::string	get_idea(int index) const;
private:
	std::string	_ideas[N_IDEAS];
	
	void		announce(std::string const msg) const;
};

#endif