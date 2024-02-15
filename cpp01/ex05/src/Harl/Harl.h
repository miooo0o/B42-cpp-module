
#ifndef HARL_H
#define HARL_H

typedef enum e_level {
	DEBUG = 0,
	INFO,
	WARNING,
	ERROR,
	LEVEL_NUMS_ITEMS
}	e_level;

#include "macro.h"
class Harl {

public:
	Harl(void);
	~Harl(void);
	void    complain( const string& level );

private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);

	typedef void	(Harl::*f_complain)(void);
};


#endif
