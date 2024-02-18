#ifndef REPLACE_H
#define REPLACE_H

/// @library for the target project
# include <sstream>
# include <fstream>

/// @library error
# include <exception>
# include <stdexcept>

/// @header macro.h
# include "macro.h"

///	@proto utils
string	get_outfile_name(const string& filename);

/// @class	Replace
class Replace {

public:
	Replace(string filename);
	~Replace(void);

	int			do_replace(string const &s1, string const &s2);
	bool		is_found(void);

private:
	string const	_infile_name;
	string const	_outfile_name;
	ifstream		_infile;
	ofstream		_outfile;
	bool			_is_found;
	
	static void	_error_fileopen(string const &msg, string const &filename);
	bool		_try_replace(string &line, string const &s1, string const &s2);
};

#endif
