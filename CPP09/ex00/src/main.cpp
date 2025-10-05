/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 09:29:31 by akdovlet          #+#    #+#             */
/*   Updated: 2025/10/05 15:32:06 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <ctime>
#include <iostream>
#include <fstream>
#include <sys/stat.h>

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
	if (dirCheck(filename))
		return (false);
	infile.open(filename);
	if (infile.fail())
	{
		perror(filename);
		return (false);
	}
	return (true);
}

// bool	parseDate(std::string str)
// {
// 	int	i = 0;
// 	int	j;

// 	while (i < str.size() && isspace(str[i]))
// 		i++;
// 	j = i;
// 	while (i < str.size() && i < j + 4)
// 	{
// 		if (!isdigit(str[i]))
// 			return (false);
// 	}
	
// }

bool	parseData()
{
	std::ifstream	dataFile;
	std::string		buffer;

	if (!openFileSafely("../data/data.csv", dataFile))
		throw FailedOpenException();
	getline(dataFile, buffer);
	if (buffer != "date,exchange_rate")
		throw CorruptedDataBase();
	while (1)
	{
		getline(dataFile, buffer);
		if (dataFile.fail())
			break ;
		
	}
	return (true);
}

#include <sstream>
#include <time.h>
#include <ctime>

int main(int ac, char **av)
{
	if (ac == 1)
		return (0);
	std::ifstream	infile;
	std::tm tm = {};
	char	*err;

	err = strptime(av[1], "%Y-%m-%d", &tm);	
	std::time_t seconds = std::mktime(&tm);
	
	if (seconds < 0)
		std::cout << "Error supposedly" << std::endl;
	
	std::cout << "seconds: " << seconds << std::endl;
	std::cout << "time: " << ctime(&seconds) << std::endl;

	char str[50];
	strftime(str, 50, "%Y-%m-%d", &tm);
	std::cout << "time: " << str  << std::endl;

}
