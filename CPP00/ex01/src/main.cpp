/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:25:12 by akdovlet          #+#    #+#             */
/*   Updated: 2025/07/01 15:54:04 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	PB;
	std::string	buffer;

	std::cout	<< "PhoneBook 1.07.1\n"
				<< "Copyright 1998 AK Software\n"
				<< "Commands: ADD, SEARCH, EXIT\n" << std::endl;
				
	while (1)
	{
		std::cout << "Main menu: " << std::flush;
		getline(std::cin,buffer);
		if (std::cin.fail() || buffer == "EXIT")
		{
			std::cout << "exit" << std::endl;
			break ;
		}
		else if (buffer == "ADD")
			PB.add();
		else if (buffer == "SEARCH")
			PB.search();
	}
}
