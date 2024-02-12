#include "Replace/Replace.h"

bool	open_file(string& filename)
{
	ifstream input_file(filename);
	return (input_file.is_open());
}

string	get_outfile_name(const string& filename)
{
	size_t	last_dot = filename.find_last_of('.');
	
	if (last_dot != string::npos)
		return (filename.substr(0, last_dot) + ".replace");
	return (filename + ".replace");

}

int	error_openfile(void)
{
	cerr << "error: fail to open file: " << SYSERROR() <<endl;
	return (EXIT_FAILURE);
}

int	error_args(void)
{
	cerr << "error: incorrect argument(s): "
	<< "usage: filename, string 1, string 2"
	<< endl;
	return (EXIT_FAILURE);
}


bool	Sed_is_for_losers(string& filename)
{
	
	ifstream infile(filename, std::ios::binary);
	ofstream outfile(get_outfile_name(filename), std::ios::binary);
	
	if (!outfile.is_open())
	{
		infile.close();
		error_openfile();
		return (false);
	}
	outfile << infile.rdbuf();
	infile.close();
	outfile.close();
	return (true);
}

bool	args_check(int ac, char **av)
{
	if (ac != 4)
		return (false);
	if (string(av[2]).empty() || string(av[2]).size() <= 0)
		return (false);
	if (string(av[3]).empty() || string(av[3]).size() <= 0)
		return (false);
	return (true);
}

bool	find_and_replace(string &filename, string s1, string s2)
{
	ifstream file(get_outfile_name(filename));
	
	if (!file.is_open())
		return (error_openfile(), false);
	
	string	line;
	while (getline(file, line))
	{
		size_t	pos = 0;
		
	}
	file.close();
	return (true);
}

int	main(int ac, char **av)
{
	string	filename;
	
	if (args_check(ac, av))
		return (error_args());
	filename = av[1];
	if (open_file(filename))
	{
		if (!Sed_is_for_losers(filename))
			return (EXIT_FAILURE);
		if (!find_and_replace(filename, string(av[2]), string(av[3])))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
// TODO: toooo c style.... think/research more