/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:56:56 by akdovlet          #+#    #+#             */
/*   Updated: 2025/07/03 17:19:43 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit )
{
	_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	_displayTimestamp();
	std::cout	<< " " << "index:" << Account::_accountIndex
				<< ";amount:" << initial_deposit
				<< ";created" << std::endl;
	_amount += initial_deposit;
	Account::_totalAmount += initial_deposit;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout	<< " " << "index:" << Account::_accountIndex
				<< ";amount:" << Account::_amount
				<< ";closed" << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout	<< " index:" << Account::_accountIndex << ";p_amount:"
				<< Account::_amount << ";deposit:" << deposit
				<< ";amount:" << Account::_amount + deposit
				<< ";nb_deposits:" << ++Account::_nbDeposits << std::endl;
	Account::_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout	<< " index:" << Account::_accountIndex << ";p_amount:"
				<< Account::_amount << ";withdrawal:";
	if (withdrawal <= Account::_amount)
	{
		std::cout	<< withdrawal << ";amount:" << Account::_amount - withdrawal
					<< ";nb_withdrawals:" << ++Account::_nbWithdrawals << std::endl;
		Account::_amount -= withdrawal;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		return (true);		
	}
	std::cout << "refused" << std::endl;
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
				<< _nbDeposits << ";withdrawals:" << _nbWithdrawals
				<< std::endl;
}
