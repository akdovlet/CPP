/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 09:29:21 by akdovlet          #+#    #+#             */
/*   Updated: 2025/10/13 18:47:47 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <ctime>
#include <time.h>
#include <ctime>
#include <iostream>

class CantDeduceFormat : public BitcoinExchange::Error
{
	const char* what() const throw() { return "Fatal error: can't deduce format"; }
};

class FailedOpenException : public BitcoinExchange::Error
{
public:
	const char* what() const throw() { return "Fatal error: can't open file"; }
};

class CorruptedDataBase : public BitcoinExchange::Error
{
	const char* what() const throw() { return "Fatal error: corrupted data base"; }
};

class InvalidDate : public BitcoinExchange::Error
{
	const char* what() const throw() { return "Invalid Date"; }
};

BitcoinExchange::BitcoinExchange(const char* filename) try : dataBase()
{
	parseData(filename);
}
catch(const std::exception& e)
{
	throw;
}

BitcoinExchange::~BitcoinExchange()
{
}

void	BitcoinExchange::printDB(void)
{
	std::map<std::time_t, float>::iterator begin = dataBase.begin();
	std::map<std::time_t, float>::iterator end = dataBase.end();
	while (begin != end)
	{
		std::cout << "Date: " << ctime(&begin->first) << " | value: " << begin->second << std::endl;
		begin++;
	}
}
