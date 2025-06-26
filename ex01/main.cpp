/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:25:12 by akdovlet          #+#    #+#             */
/*   Updated: 2025/06/26 20:13:44 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	PB;
	std::string	buffer;
	
	while (getline(std::cin, buffer))
	{
		if (std::cin.eof())
			break ;
		if (buffer == "ADD")
			PB.add();
	}
}
