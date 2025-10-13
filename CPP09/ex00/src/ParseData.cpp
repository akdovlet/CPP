/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParseData.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:40:51 by akdovlet          #+#    #+#             */
/*   Updated: 2025/10/13 19:01:13 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <sstream>
#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include <exception>
#include <cstring>

char	getFormat(const std::string& str)
{
	char		separator;
	std::size_t	i = 0;

	while (i < str.size() && isspace(str[i]))
		i++;
	if (i == str.size() || !isalpha(str[i]))
		throw std::runtime_error("statement does not start with word");
	while (i < str.size() && isalpha(str[i]))
		i++;
	while (i < str.size() && isspace(str[i]))
		i++;
	if (i == str.size())
		throw std::runtime_error("Can't deduce format");
	separator = str[i++];
	while (i < str.size() && isspace(str[i]))
		i++;
	if (i == str.size() || !isalpha(str[i]))
		throw std::runtime_error("Invalid format, separator not followed by word");
	return (separator);
}

bool	dirCheck(const char *filename)
{
	struct stat	s;

	if (!stat(filename, &s))
	{
		if (s.st_mode & S_IFDIR)
			return (false);		
	}
	else
		return (false);
	return (true);
}

void	openFileSafely(const char *filename, std::ifstream& infile)
{
	if (!dirCheck(filename))
		throw std::runtime_error("Error: " + std::string(filename) + " is directory");
	infile.open(filename);
	if (infile.fail())
		throw std::runtime_error("Error: " + std::string(strerror(errno)));
}

int	checkYear(const std::string& str, int& i)
{
	int	digits = 0;
	int	year; 
	std::stringstream	sstr(str.substr(0, 4));
	while (str[i] && digits < 4)
	{
		if (!isdigit(str[i]))
			throw std::runtime_error("Error: bad input => " + str);
		digits++;
		(i)++;
	}
	if (digits < 4 || str[i] != '-')
		throw std::runtime_error("Error: bad input => " + str);
	(i)++;
	sstr >> year;
	if (sstr.fail() || year < 1970 || year > 2025)
	{
		throw std::runtime_error("Error: bad input => " + str);
	}
	return (year);
}

bool	BitcoinExchange::isLeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return (true);
	return (false);
}

int	checkMonth(const std::string& str, int& i)
{
	int month;
	int digits = 0;
	std::stringstream sstr(str.substr(i, 2));

	while (str[i] && digits < 2)
	{
		if (!isdigit(str[i]))
			throw std::runtime_error("Error: bad input => " + str);
		digits++;
		(i)++;
	}
	if (digits < 2 || str[i] != '-')
		throw std::runtime_error("Error: bad input => " + str);
	(i)++;
	sstr >> month;
	if (sstr.fail() || month < 1 || month > 12)
		throw std::runtime_error("Error: bad input => " + str);
	return (month);
}

int	checkDay(const std::string& str, int& i)
{
	int day;
	int digits = 0;
	std::stringstream sstr(str.substr(i, 2));

	while (str[i] && digits < 2)
	{
		if (!isdigit(str[i]))
			throw std::runtime_error("Error: bad input => " + str);
		digits++;
		(i)++;
	}
	if (digits < 2 || isdigit(str[i]))
		throw std::runtime_error("Error: bad input => " + str);
	sstr >> day;
	if (sstr.fail() || day < 1 || day > 31)
		throw std::runtime_error("Error: bad input => " + str);
	return (day);
}

void	parseDate(std::tm& tm, const std::string& str, int& i)
{
	int 	year;
	int		month;
	int		day;
	bool	isLeap;

	year = checkYear(str, i);
	tm.tm_year = year - 1900;
	isLeap = BitcoinExchange::isLeapYear(year);

	month = checkMonth(str, i);

	tm.tm_mon = month - 1;
	day = checkDay(str, i);

	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		throw std::runtime_error("Error: bad input => " + str);
	if (month == 2 && ((day > 28 && !isLeap) || (isLeap && day > 29)))
		throw std::runtime_error("Error: bad input => " + str);
	tm.tm_mday = day;
}

void	parseValue(char sep, int& i, float& value, const std::string& str)
{
	bool hasFraction = false;
	
	while (str[i] && isspace(str[i]))
		i++;
	if (str[i++] != sep)
		throw std::runtime_error("Invalid format, no separator");
	while (str[i] && isspace(str[i]))
		i++;
	int	j = i;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (hasFraction)
				throw std::runtime_error("Error: Invalid value");
			hasFraction = true;
			i++;
		}
		if (!isdigit(str[i]))
			throw std::runtime_error("Error: Invalid value");
		i++;
	}	
	std::stringstream sstr(str.substr(j, i));
	sstr >> value;
	if (sstr.fail())
		throw std::runtime_error("Error: Invalid value: conversion impossible");
}

void	extractDateAndValue(char sep, float& value, std::tm& tm, const std::string& str)
{
	int	i = 0;
	std::string date(str.substr(0, str.find_first_of(sep)));
	try
	{
		parseDate(tm, date, i);
		parseValue(sep, i, value, str);
	}
	catch(const std::exception& e)
	{
		throw;
	}
}

void	BitcoinExchange::parseData(const char* filename)
{
	std::ifstream	dataFile;
	std::string		buffer;
	std::tm 		tm = {};
	float			value = 0;
	char			separator;
	
	openFileSafely(filename, dataFile);
	getline(dataFile, buffer);
	try
	{
		separator = getFormat(buffer);
	}
	catch(const std::exception& e)
	{
		dataFile.close();
		throw;
	}
	while (1)
	{
		getline(dataFile, buffer);
		if (dataFile.fail())
			break ;
		try
		{
			extractDateAndValue(separator, value, tm, buffer);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Corrupted Data Base: " << e.what() << '\n';
			dataFile.close();
			throw ;
		}
		dataBase.insert(std::pair<std::time_t, float>(std::mktime(&tm), value));
	}
	dataFile.close();
}

void	BitcoinExchange::printValue(std::tm& tm, std::string& date, float value)
{
	std::map<std::time_t, float>::iterator it;
	std::map<std::time_t, float>::iterator prev;
	std::map<std::time_t, float>::iterator end;
	
	std::time_t key = std::mktime(&tm);

	if (value < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return ;	
	}
	if (value > 1000)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return ;	
	}
	it = dataBase.lower_bound(std::mktime(&tm));
	if (it == dataBase.end())
	{
		it--;
		std::cout << date << " => " << value << " = " << it->second * value << std::endl;
	}
	else if (it == dataBase.begin())
	{
		std::cout << date << " => " << value << " = " << it->second * value << std::endl;
	}
	else
	{
		if (it->first == key)
			std::cout << date << " => " << value << " = " << it->second * value << std::endl;
		else
		{
			it--;
			std::cout << date << " => " << value << " = " << it->second * value << std::endl;
		}
	}
}

void	BitcoinExchange::parseInput(const char* file)
{
	std::ifstream	inFile;
	std::string		buffer;
	std::tm			tm = {};
	float			value = 0;
	char			separator;

	openFileSafely(file, inFile);
	getline(inFile, buffer);
	try
	{
		separator = getFormat(buffer);
	}
	catch(const std::exception& e)
	{
		inFile.close();
		throw;
	}
	while (1)
	{
		getline(inFile, buffer);
		if (inFile.fail())
			break ;
		try
		{
			extractDateAndValue(separator, value, tm, buffer);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
			continue ;
		}
		printValue(tm, buffer, value);
	}
	inFile.close();
}

void	BitcoinExchange::getExchangeRate(const char* infile)
{
	try
	{
		parseInput(infile);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

