/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:56:56 by akdovlet          #+#    #+#             */
/*   Updated: 2025/07/02 12:21:18 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

Account::Account(int initial_deposit )
{
	_displayTimestamp();
	std::cout	<< " " << "index:" << Account::_accountIndex
				<< ";amount:" << initial_deposit
				<< ";created" << std::endl;
	Account::_accountIndex = _nbAccounts;
	Account::_amount += initial_deposit;
	_totalAmount += initial_deposit;
	_nbAccounts++;
}

Account::~Account(void)
{
	/*I'm supposed to do something here*/
}

void	Account::makeDeposit(int deposit)
{
	Account::_amount += deposit;
	Account::_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "deposit:" << deposit << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	if (withdrawal <= Account::_amount)
	{
		Account::_amount -= withdrawal;
		Account::_nbWithdrawals++;
		_nbWithdrawals++;
		_totalAmount -= withdrawal;
		return (true);		
	}
	return (false);
}

int	Account::checkAmount(void) const
{
	return (Account::_amount);
}

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::_displayTimestamp(void)
{
	char		time_string[18];
	time_t		local_t;
	struct tm	*curr_t;
	
	time(&local_t);
	curr_t = localtime(&local_t);
	std::strftime(time_string,18,"[%G%m%d_%H%M%S]", curr_t);
	std::cout << time_string;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout	<< " " << "accounts:" << _nbAccounts
				<< ";total:" << _totalAmount << ";deposits:"
				<< _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals
				<< std::endl;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout	<< " " << "index:" << Account::_accountIndex
				<< ";amount:" << Account::_amount << ";deposits:"
				<< _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals
				<< std::endl;

}
