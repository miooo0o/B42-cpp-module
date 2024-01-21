#include "Account.hpp"

#include <iostream>
#include <ctime>

using namespace std;

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account()
		: _accountIndex(0),
		  _amount(0),
		  _nbDeposits(0),
		  _nbWithdrawals(0)
{
	++_nbAccounts;
}

Account::Account(int initial_deposit)
		: _accountIndex(_nbAccounts),
		  _amount(initial_deposit),
		  _nbDeposits(0),
		  _nbWithdrawals(0)
{
	_totalAmount += initial_deposit;
	++_nbAccounts;
	++_totalNbDeposits;
}

int Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}
int	Account::getNbDeposits( void )
{
	
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}


void	Account::_displayTimestamp( void )
{

}

void	Account::displayAccountsInfos( void )
{
	char    timeBuffer[20];
}