/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 09:28:58 by akdovlet          #+#    #+#             */
/*   Updated: 2025/10/26 16:39:58 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <ctime>
#include <utility>
#include <string>

class BitcoinExchange
{
private:
	std::map<time_t, float>	dataBase;

	void	parseData(const char* filename);
	void	parseInput(const char* filename);
	void	printValue(std::tm& tm, std::string& date, float value);
public:
	class Error;

	BitcoinExchange(const char* dB = "data/data.csv");
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(BitcoinExchange other);
	~BitcoinExchange();
	
	void	getExchangeRate(const char* infile);
	
	void	swap(BitcoinExchange& a, BitcoinExchange& b);

	static bool	isLeapYear(int year);

	void	printDB();
};

class BitcoinExchange::Error: public std::exception {};
class CantDeduceFormat;
class FailedOpenException;
class CorruptedDataBase;
class InvalidDate;

#endif
