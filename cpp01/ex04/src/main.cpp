#include "Replace/Replace.h"

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

// TODO: toooo c style.... think/research more
int	main(int ac, char **av)
{
	string	filename;
	if (args_check(ac, av))
		return (error_args());
	Replace	res = Replace(av[1]);
	if (res.do_replace(av[2], av[3]) == INVALID)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}