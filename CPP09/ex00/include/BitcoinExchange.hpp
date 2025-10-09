/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 09:28:58 by akdovlet          #+#    #+#             */
/*   Updated: 2025/10/09 19:37:36 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <ctime>
#include <utility>

class BitcoinExchange
{
private:
	std::map<time_t, float>	dataBase;

	bool	parseData();
public:
	class Error;
	
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(BitcoinExchange other);
	~BitcoinExchange();

	void	swap(BitcoinExchange& a, BitcoinExchange& b);

	static bool	isLeapYear(int year);

	void	printDB();
};

class BitcoinExchange::Error: public std::exception {};

#endif
