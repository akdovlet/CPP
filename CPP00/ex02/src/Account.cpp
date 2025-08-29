/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:56:56 by akdovlet          #+#    #+#             */
/*   Updated: 2025/08/29 20:36:22 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _accountIndex(Account::_nbAccounts++), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_displayTimestamp();
	std::cout	<< " " << "index:" << _accountIndex
				<< ";amount:" << initial_deposit
				<< ";created" << std::endl;
	Account::_totalAmount += initial_deposit;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout	<< " " << "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";closed" << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout	<< " index:" << _accountIndex << ";p_amount:"
				<< _amount << ";deposit:" << deposit
				<< ";amount:" << _amount + deposit
				<< ";nb_deposits:" << ++_nbDeposits << std::endl;
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout	<< " index:" << _accountIndex << ";p_amount:"
				<< _amount << ";withdrawal:";
	if (withdrawal <= _amount)
	{
		std::cout	<< withdrawal << ";amount:" << _amount - withdrawal
					<< ";nb_withdrawals:" << ++_nbWithdrawals << std::endl;
		_amount -= withdrawal;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		return (true);		
	}
	std::cout << "refused" << std::endl;
	return (false);
}

int	Account::checkAmount(void) const
{
	return (_amount);
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
	std::cout	<< " " << "index:" << _accountIndex
				<< ";amount:" << _amount << ";deposits:"
				<< _nbDeposits << ";withdrawals:" << _nbWithdrawals
				<< std::endl;
}
