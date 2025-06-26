/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 19:16:01 by akdovlet          #+#    #+#             */
/*   Updated: 2025/06/26 19:58:31 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int get_value(std::string prompt, std::string &arg)
{
	std::cout << "Enter " << prompt << ": " << std::flush;
	getline(std::cin, arg);
	if (std::cin.eof())
	{
		std::cout << "Canceled form, nothing was saved" << std::endl;
		return (1);
	}
	return (0);
}

int		Contact::create(void)
{
	int			index;
	std::string	buffer;

	index = 0;
	std::cout << "Enter first name: ";
	{
		if (std::cin.eof())
		{
			std::cout << "Canceled form, nothing was saved" << std::endl;
			return (1);
		}
		if (index == 0)
			Contact::_FirstName = buffer;
	}
	return (0);
}
