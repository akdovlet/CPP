/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 09:29:21 by akdovlet          #+#    #+#             */
/*   Updated: 2025/10/09 19:38:55 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <ctime>
#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <sstream>
#include <time.h>
#include <ctime>

class CantDeduceFormat : public BitcoinExchange::Error
{
	const char* what() const throw() { return "Fatal error: can't deduce format"; }
};

class FailedOpenException : public BitcoinExchange::Error
{
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

BitcoinExchange::BitcoinExchange() try : dataBase()
{
	parseData();
}
catch(const std::exception& e)
{
	throw;
}

char	getFormat(const std::string& str)
{
	char		separator;
	std::size_t	i = 0;

	while (i < str.size() && isspace(str[i]))
		i++;
	if (i == str.size() || !isalpha(str[i]))
		throw std::runtime_error(", statement does not start with word");
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
		{
			std::cerr << "Error: " << filename << " is directory" << std::endl;
			return (false);
		}	
	}
	else
	{
		std::cerr << "Error: " << filename <<": invalid path" << std::endl;
		return (false);		
	}
	return (true);
}

bool	openFileSafely(const char *filename, std::ifstream& infile)
{
	if (!dirCheck(filename))
		return (false);
	infile.open(filename);
	if (infile.fail())
	{
		perror(filename);
		return (false);
	}
	return (true);
}

BitcoinExchange::~BitcoinExchange()
{
}

int	checkYear(const std::string& str, int& i)
{
	int	digits = 0;
	int	year;
	std::stringstream sstr(str.substr(0, 4));
	
	while (str[i] && digits < 4)
	{
		if (!isdigit(str[i]))
			throw std::runtime_error("Invalid data entry");
		digits++;
		(i)++;
	}
	if (digits < 4 || str[i] != '-')
		throw std::runtime_error("Invalid data entry2");
	(i)++;
	sstr >> year;
	if (sstr.fail() || year < 1970 || year > 2025)
	{
		throw std::runtime_error("Invalid data entry3");
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
			throw std::runtime_error("Invalid month entry");
		digits++;
		(i)++;
	}
	if (digits < 2 || str[i] != '-')
		throw std::runtime_error("invalid month entry");
	(i)++;
	sstr >> month;
	if (sstr.fail() || month < 1 || month > 12)
		throw std::runtime_error("invalid month entry");
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
			throw std::runtime_error("Invalid day entry");
		digits++;
		(i)++;
	}
	if (digits < 2 || isdigit(str[i]))
		throw std::runtime_error("invalid day entry");
	sstr >> day;
	if (sstr.fail() || day < 1 || day > 31)
		throw std::runtime_error("invalid day entry");
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
		throw std::runtime_error("Impossible date");
	if (month == 2 && ((day > 28 && !isLeap) || (isLeap && day > 29)))
		throw std::runtime_error("impossible date");
	tm.tm_mday = day;
}

void	parseValue(char sep, int& i, float& value, const std::string& str)
{
	bool hasFraction = false;
	
	while (str[i] && isspace(str[i]))
	i++;
	std::cout << "str[i] is: " << str[i] << std::endl;
	if (str[i++] != sep)
		throw std::runtime_error("Invalid format, no separator");
	while (str[i] && isspace(str[i]))
		i++;
	int	j = i;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (hasFraction)
				throw std::runtime_error("Invalid value");
			hasFraction = true;
			i++;
		}
		if (!isdigit(str[i]))
			throw std::runtime_error("Invalid value");
		i++;
	}	
	std::stringstream sstr(str.substr(j, i));
	std::cout << "substr: " << str.substr(j, i) << std::endl;
	sstr >> value;
	if (sstr.fail())
		throw std::runtime_error("sstr.fail()");
}

void	extractDateAndValue(char sep, float& value, std::tm& tm, const std::string& str)
{
	int	i = 0;
	
	try
	{
		parseDate(tm, str, i);
		parseValue(sep, i, value, str);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		throw;
	}
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

bool	BitcoinExchange::parseData()
{
	std::ifstream	dataFile;
	std::string		buffer;
	std::tm 		tm = {};
	float			value = 0;
	char			separator;
	

	if (!openFileSafely("data/data.csv", dataFile))
		throw FailedOpenException();
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
			std::cerr << e.what() << '\n';
			dataFile.close();
			throw;
		}
		dataBase.insert(std::pair<std::time_t, float>(std::mktime(&tm), value));
	}
	return (true);
}
