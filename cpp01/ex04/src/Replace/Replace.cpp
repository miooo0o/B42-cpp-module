#include "Replace.h"

/// @brief	constructor functions
/// @note	initialization list always with `filename`
Replace::Replace(string filename)
: _infile_name(filename), _outfil_ename(get_outfile_name(_infile_name))
{
	_is_found = false;
	_in.open(_infile_name);
	if (!_in.is_open())
		_error_fileopen("for reading", _infile_name);
	_out.open(_outfil_ename);
	if (!_out.is_open())
	{
		_in.close();
		_error_fileopen("for writing", _outfil_ename);
	}
}

Replace::~Replace(void)
{
	_in.close();
	_out.close();
}

///////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief	public
int	Replace::do_replace(string const &s1, string const &s2)
{
	while (!_in.eof())
	{
		string	tmp;
		std::getline(_in, tmp);
		try
		{
			_try_replace(tmp, s1, s2);
			_out << tmp << endl;
		}
		catch (std::exception &e)
		{
			cerr << e.what() << endl;
			return (INVALID);
		}
	}
	return (VALID);
}

bool	Replace::is_found(void)
{
	if (_is_found)
		return (true);
	return (false);
}

/// @brief	private, class object functions
/// @note	error handling depended on
void	Replace::_error_fileopen(string const &msg, string const &filename)
{
	cerr << "error: " << msg << ": "<< filename << "." << endl;
	throw std::runtime_error("Failed to open file: " + filename);
}

bool	Replace::_try_replace(string &line, string const &s1, string const &s2)
{
	size_t		pos = 0;
	
	while ((pos = line.find(s1, pos)) != string::npos)
	{
		if (pos + s1.length() <= line.length())
		{
			_is_found = true;
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		else
			throw std::out_of_range("substring not found within bounds");
	}
	return (true);
}

///////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief	utils functions
/// @note	string.find_last_of:
/// Find the last position of a character by a given param in the string
/// @note	string::npos: If cannot find a specific location in string
string	get_outfile_name(const string& filename)
{
	size_t	last_dot = filename.find_last_of('.');
	
	if (last_dot != string::npos)
		return (filename.substr(0, last_dot) + ".replace");
	return (filename + ".replace");
	
}