#include "Account.hpp"

#include <iostream>
#include <ctime>

using	std::cout;
using	std::endl;
using	std::flush;

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
	_displayTimestamp();
	cout << "index:" <<  _accountIndex << ";"
		 << "amount:" <<  _amount << ";"
		 << "created" << endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	cout << "index:" <<  _accountIndex << ";"
		 << "amount:" <<  _amount << ";"
		 << "closed" << endl;
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

// [19920104_091532]
void	Account::_displayTimestamp( void )
{
	char	timestamp[16];
	time_t	now;
	tm		*ltm;
	
	now = time(nullptr);
	ltm = localtime(&now);
	strftime(timestamp, sizeof(timestamp), "%Y%m%d_%H%M%S", ltm);
	cout << "[" << timestamp << "] " << flush;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	++_nbDeposits;
	++_totalNbDeposits;
	cout << "index:" << _accountIndex
	<< ";p_amount:" << _amount
	<< ";deposit:" << deposit
	<< flush;
	_amount += deposit;
	cout << ";amount:" << _amount
	<< ";nb_deposits:" << _nbDeposits
	<< endl;
	_totalAmount += deposit;
}

//[19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	if (_amount - withdrawal > 0)
	{
		++_nbWithdrawals;
		++_totalNbWithdrawals;
		cout << "index:" << _accountIndex
			 << ";p_amount:" << _amount
			 << ";withdrawal:" << withdrawal
			 << flush;
		_amount -= withdrawal;
		cout << ";amount:" << _amount
			 << ";nb_withdrawals:" << _nbWithdrawals
			 << endl;
		_totalAmount -= withdrawal;
		return (true);
	}
	cout << "index:" << _accountIndex
		 << ";p_amount:" << _amount
		 << ";withdrawal:" << "refused"
		 << endl;
	return (false);
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

//[19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	cout << "index:" << _accountIndex
		 << ";amount:" << _amount
		 << ";deposits:" << _nbDeposits
		 << ";withdrawals:" << _nbWithdrawals
		 << endl;
}

//[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	cout << "accounts:" << _nbAccounts
		 << ";total:" << _totalAmount
		 << ";deposits:" << _totalNbDeposits
		 << ";withdrawals:" << _totalNbWithdrawals
		 << endl;
}