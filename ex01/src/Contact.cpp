/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 19:16:01 by akdovlet          #+#    #+#             */
/*   Updated: 2025/06/27 18:47:50 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iomanip>
#include <limits>
#include <ios>
#include <cstdio>

bool	string_is_valid(std::string str)
{
	size_t	i;
	bool	notempty;
	
	notempty = false;
	i = 0;
	while (i < str.size())
	{
		if (std::isalnum(str[i]))
			notempty = true;
		if (!std::isalnum(str[i]) && !std::isspace(str[i]))
			return (false);
		i++;
	}
	if (notempty)
		return (true);
	return (false);
}

bool	number_is_valid(std::string str)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i] && std::isspace(str[i]))
		i++;
	if (str[i++] != '+')
		return (false);
	while (i < str.size())
	{
		if (std::isdigit(str[i]))
			count++;
		if (!std::isdigit(str[i]) && !std::isspace(str[i]))
			return (false);
		i++;
	}
	if (count >= 4 && count <= 17)
		return (true);
	return (false);
}

int get_value(std::string prompt, std::string &arg)
{
	while (1)
	{
		std::cout << "Enter " << prompt << ": " << std::flush;
		getline(std::cin, arg);
		if (std::cin.fail())
		{
			clearerr(stdin);
			std::cout << "\n";
			break ;
		}
		if (arg.empty())
		{
			std::cout << "Field can not be empty, try again" << std::endl;
			continue;
		}
		if (prompt != "phone number" && string_is_valid(arg))
			return (0);
		else if (prompt == "phone number" && number_is_valid(arg))
			return (0);
		else
		{
			std::cout << "Invalid format, try again" << std::endl;
			continue ;
		}
	}
	return (1);
}

int		Contact::create(void)
{
	int			index;
	std::string	buffer;

	index = 0;
	std::cout << "New contact form" << std::endl;
	if (get_value("first name", Contact::_FirstName))
		return (1);
	if (get_value("last name", Contact::_LastName))
		return (1);
	if (get_value("nickname", Contact::_Nickname))
		return (1);
	if (get_value("phone number", Contact::_PhoneNumber))
		return (1);
	if (get_value("darkest secret", Contact::_Secret))
		return (1);
	return (0);
}

std::string	formatting(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + '.');
	return (str);
}

void	Contact::print_info(void)
{
	std::cout	<< "|" << std::right << std::setw(10) << formatting(_FirstName)
				<< "|" << std::right << std::setw(10) << formatting(_LastName)
				<< "|" << std::right << std::setw(10) << formatting(_Nickname)
				<< "|" << std::endl;
}
