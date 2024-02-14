#include "Replace.h"


string	get_outfile_name(const string& filename)
{
	size_t	last_dot = filename.find_last_of('.');
	
	if (last_dot != string::npos)
		return (filename.substr(0, last_dot) + ".replace");
	return (filename + ".replace");
	
}



Replace::Replace(string filename)
: _infile(filename), _outfile(get_outfile_name(_infile))
{
}

bool	try_replace(string const &s1, string const &s2)
{

}

int	Replace::Sed_is_for_losers(string const &s1, string const &s2)
{
	ifstream in(_infile);
	if (!in.is_open())
		std::runtime_error("Failed to open file: " + _infile);
	ofstream out(_outfile);
	if (!out.is_open())
	{
		in.close();
		std::runtime_error("Failed to open file: " + _outfile);
	}
	
	return (VALID);
}