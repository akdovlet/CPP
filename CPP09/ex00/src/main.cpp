/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 09:29:31 by akdovlet          #+#    #+#             */
/*   Updated: 2025/10/13 18:50:49 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"

// int main(int ac, char **av)
// {
// 	if (ac == 1)
// 		return (0);
// 	std::ifstream	infile;
// 	std::tm 		tm = {};
// 	char			*err;

// 	err = strptime(av[1], "%Y-%m-%d", &tm);	
// 	std::time_t seconds = std::mktime(&tm);

// 	if (seconds < 0)
// 		std::cout << "Error supposedly" << std::endl;

// 	// std::cout << "seconds: " << seconds << std::endl;
// 	// std::cout << "time: " << ctime(&seconds) << std::endl;

// 	// char str[50];
// 	// strftime(str, 50, "%Y-%m-%d", &tm);
// 	// std::cout << "time: " << str  << std::endl;

// 	try {
// 		std::cout << "separator: " << getFormat(av[1]) << std::endl;
// 	} catch (BitcoinExchange::Error const &) { std::cout << "caught btc exception" << std::endl;}
// }

int main(int ac, char **av)
{
	if (ac > 1)
	{
		try
		{
			BitcoinExchange btc;
			btc.getExchangeRate(av[1]);
		}
		catch(const std::exception& e)
		{
		}		
	}
	return (0);
}
