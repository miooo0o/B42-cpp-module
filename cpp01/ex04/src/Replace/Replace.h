#ifndef REPLACE_H
#define REPLACE_H

#include "macro.h"

class Replace {

public:
	Replace(string filename);
	~Replace(void);
	int	do_replace(string const &s1, string const &s2);
	
private:
	string const	_infile;
	string const	_outfile;
};

#endif
