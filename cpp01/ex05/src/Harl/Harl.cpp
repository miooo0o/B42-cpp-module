#include "Harl.h"

/// @brief	constructor
Harl::Harl(){}
Harl::~Harl(){}

/// @brief	public
void	Harl::complain(const string& level)
{
	string		levels[LEVEL_NUMS_ITEMS] = {
				"DEBUG",
				"INFO",
				"WARNING",
				"ERROR"
				};
	f_complain	f[LEVEL_NUMS_ITEMS] = {
				&Harl::debug,
				&Harl::info,
				&Harl::warning,
				&Harl::error
				};
	for (int i = 0; i < LEVEL_NUMS_ITEMS; i++)
	{
		if (!level.empty() && levels[i] == level)
		{
			(this->*f[i])();
			return ;
		}
	}
	cerr << "error: Harl couldn't find any words...." << endl;
}

/// @brief	private
void	Harl::debug(void)
{
	cout << "Harl: " << "error: " <<
	"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. "
	"I really do!"
	<< endl;
}

void	Harl::info(void)
{
	cout << "Harl: " << "info: " <<
	"I cannot believe adding extra bacon costs more money. "
	"You didn’t putenough bacon in my burger! If you did, I wouldn’t be asking for more!"
	<< endl;
	
}

void	Harl::warning(void)
{
	cout << "Harl: " << "warning: " <<
	"I think I deserve to have some extra bacon for free. "
	"I’ve been coming foryears whereas you started working here since last month."
	<< endl;
}

void	Harl::error(void)
{
	cout << "Harl: " << "error: " <<
	"This is unacceptable! "
	"I want to speak to the manager now."
	<< endl;
}