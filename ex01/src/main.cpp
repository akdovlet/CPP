/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:25:12 by akdovlet          #+#    #+#             */
/*   Updated: 2025/06/27 18:50:09 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <limits>

int main(void)
{
	PhoneBook	PB;
	std::string	buffer;

	std::cout	<< "PhoneBook 1.07.1\n"
				<< "Copyright 1981-1994 AK Software\n"
				<< "Main menu\n"
				<< "Commands: ADD, SEARCH, EXIT" << std::endl;
				
	while (1)
	{
		getline(std::cin,buffer);
		if (std::cin.fail() || buffer == "EXIT")
		{
			std::cout << "exit" << std::endl;
			break ;
		}
		else if (buffer == "ADD")
		{
			PB.add();
			std::cin.clear();
			std::cout << "Main menu" << std::endl;
		}
		else if (buffer == "SEARCH")
			PB.search();
	}
}
