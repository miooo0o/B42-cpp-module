#include "macro.h"

bool	open_file(string& filename)
{
	ifstream input_file(filename);
	return (input_file.is_open());
}

string	get_out_filename(const string& filename)
{
	size_t	last_dot = filename.find_last_of('.');
	
	if (last_dot != string::npos)
		return (filename.substr(0, last_dot) + ".replace");
	return (filename + ".replace");

}

bool	Sed_is_for_losers(string& filename)
{
	ifstream input_file(filename, std::ios::binary);
	ifstream out_file(get_out_filename(filename), std::ios::binary);
	
}

int	main(int ac, char **av)
{
	string	filename;
	
	if (ac == 4)
	{
		filename = av[1];
		if (open_file(filename))
		{
			if (Sed_is_for_losers(filename))
				return (EXIT_SUCCESS);
			cerr << "error:" << "something happens" << "." <<endl;
			return (EXIT_FAILURE);
		}
		cerr << "error: can not open " << filename << "." <<endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_FAILURE);
}