/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 09:28:58 by akdovlet          #+#    #+#             */
/*   Updated: 2025/10/05 15:32:03 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <ctime>

class FailedOpenException : public std::exception
{
	const char* what() const throw() { return "Fatal error: can't open file"; }
};

class CorruptedDataBase : public std::exception
{
	const char* what() const throw() { return "Fatal error: corrupted data base"; }
};

class InvalidDate : public std::exception
{
	const char* what() const throw() { return "Invalid Date"; }
};

class BitcoinExchange
{
private:
	std::map<time_t, double>	data_base;
public:
	BitcoinExchange(const char* str = 0);
	BitcoinExchange(const BitcoinExchange& other);
	~BitcoinExchange();

};

// BitcoinExchange::BitcoinExchange(const char* str)
// {
// }

// BitcoinExchange::~BitcoinExchange()
// {
// }


#endif
