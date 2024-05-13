#include "Replace/Replace.h"

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
	if (string(av[2]).empty())
		return (false);
	if (string(av[3]).empty())
		return (false);
	return (true);
}

int	main(int ac, char **av)
{
	string	filename;
	if (!args_check(ac, av))
		return (error_args());
	try
	{
		Replace	res = Replace(av[1]);
		if (res.do_replace(av[2], av[3]) != VALID)
			return (EXIT_FAILURE);
		if (!res.is_found())
			cout << "except_replace: no matching strings were found." << endl;
		else
			cout << "except_replace: replaced all of the target strings with new ones." << endl;
	}
	catch (const std::exception &e)
	{
		cerr << e.what() << endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}