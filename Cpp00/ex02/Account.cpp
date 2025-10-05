	#include"Account.hpp"
	#include <ctime>
	#include<string>
	#include<iostream>

	int	Account::_nbAccounts = 0;
	int	Account::_totalAmount = 0;
	int	Account::_totalNbDeposits = 0;
	int	Account::_totalNbWithdrawals = 0;

	Account::Account( int initial_deposit ) : _amount(initial_deposit)
	{
		_displayTimestamp();
		this->_accountIndex = Account::_nbAccounts;
		Account::_nbAccounts++;
		std::cout<<"index:"<<this->_accountIndex<<";amount:"
				<<this->_amount<<";created"<<std::endl;
		Account::_totalAmount += this->_amount;
		this->_nbDeposits = 0;
		this->_nbWithdrawals = 0;

	}

	Account::Account( void )
	{
		_displayTimestamp();
		Account::_nbAccounts++;
		this->_accountIndex = Account::_nbAccounts;
		this->_amount = 0;
		std::cout<<"index:"<<this->_accountIndex<<";amount:"
				<<this->_amount<<";created"<<std::endl;
	}

	Account::~Account( void )
	{
		_displayTimestamp();
		std::cout<<"index:"<<this->_accountIndex<<";amount:"
				<<this->_amount<<";closed"<<std::endl;
	}

	int		Account::checkAmount( void ) const
	{
		return(this->_amount);
	}

	void	Account::displayStatus( void ) const
	{
		_displayTimestamp();
		std::cout<<"index:"<<this->_accountIndex<<";amount:"
				<<this->_amount<<";deposits:"<<this->_nbDeposits
				<<";withdrawals:"<<this->_nbWithdrawals<<std::endl;
	}

	bool	Account::makeWithdrawal( int withdrawal )
	{
		if (withdrawal <= 0 || (this->_amount - withdrawal) < 0)
		{
			_displayTimestamp();
			std::cout<<"index:"<<this->_accountIndex<<";p_amount:"
					<<this->_amount<<";withdrawal:refused"<<std::endl;
			return(0);
		}
		_displayTimestamp();
		std::cout<<"index:"<<this->_accountIndex<<";p_amount:"
				<<this->_amount<<";withdrawal:"<<withdrawal<<";amount:";
		this->_nbWithdrawals++;
		this->_amount -= withdrawal;
		std::cout<<this->_amount<<";nb_withdrawals:"<<this->_nbWithdrawals<<std::endl;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
		return(1);
	}

	void	Account::makeDeposit( int deposit )
	{
		if (deposit <= 0)
			return;
		_displayTimestamp();
		std::cout<<"index:"<<this->_accountIndex<<";p_amount:"
				<<this->_amount<<";deposit:"<<deposit<<";amount:";
		this->_nbDeposits++;
		this->_amount += deposit;
		std::cout<<this->_amount<<";nb_deposits:"<<this->_nbDeposits<<std::endl;
		Account::_totalAmount += deposit;
		Account::_totalNbDeposits++;
	}

	void	Account::displayAccountsInfos( void )
	{
		Account::_displayTimestamp();
		std::cout<<"accounts:"<<Account::_nbAccounts<<";total:"<<Account::_totalAmount<<";deposits:"
				<<Account::_totalNbDeposits<<";withdrawals:"<<Account::_totalNbWithdrawals<<std::endl;

	}

	void	Account::_displayTimestamp( void )
	{
		time_t timestamp;
		struct tm *timeinfo;

		time(&timestamp);
		timeinfo = localtime(&timestamp);

		std::cout << "["
				  << (timeinfo->tm_year + 1900)
				  << (timeinfo->tm_mon + 1 < 10 ? "0" : "") << (timeinfo->tm_mon + 1)
				  << (timeinfo->tm_mday < 10 ? "0" : "") << timeinfo->tm_mday
				  << "_"
				  << (timeinfo->tm_hour < 10 ? "0" : "") << timeinfo->tm_hour
				  << (timeinfo->tm_min < 10 ? "0" : "") << timeinfo->tm_min
				  << (timeinfo->tm_sec < 10 ? "0" : "") << timeinfo->tm_sec
				  << "] ";
	}

	int	Account::getNbAccounts( void )
	{
		return(Account::_nbAccounts);
	}

	int	Account::getTotalAmount( void )
	{
		return(Account::_totalAmount);
	}

	int	Account::getNbDeposits( void )
	{
		return(Account::_totalNbDeposits);
	}

	int	Account::getNbWithdrawals( void )
	{
		return(Account::_totalNbWithdrawals);
	}
