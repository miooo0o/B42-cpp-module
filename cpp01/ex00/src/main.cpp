# include "Zombie/Zombie.h"


void	who_are_you(void)
{
	cout << "let's revive!" << endl
		 << "who are you?" << endl
		 << ": " << flush;
}

void	you_reborn_heap_allocation(string input)
{
	Zombie	*new_you;
	
	if (input.empty())
		input = "Pikachu";
	new_you = newZombie(input);
	new_you->announce();
	delete new_you;
}

void	you_reborn_stack(string input)
{
	if (input.empty())
		input = "Pikachu";
	randomChump(input);
}

int main(void)
{
	string	input;
	
	while (who_are_you(), getline(cin, input))
	{
		if (cin.good())
		{
			if (input.size() > 5)
				you_reborn_heap_allocation(input);
			else
				you_reborn_stack(input);
			break ;
		}
	}
	return (EXIT_SUCCESS);
}