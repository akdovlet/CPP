/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 19:16:01 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/03 15:32:06 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iomanip>
#include <cstdio>

bool	string_is_valid(std::string str)
{
	size_t	i;
	bool	notempty;
	
	notempty = false;
	i = 0;
	while (i < str.size())
	{
		if (!notempty && std::isalnum(str[i]))
			notempty = true;
		if (!std::isalnum(str[i]) && !std::isspace(str[i]) && str[i] != '-')
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
	if (str[i] != '+' && !std::isdigit(str[i]))
		return (false);
	if (std::isdigit(str[i++]))
		count++;
	while (i < str.size())
	{
		if (std::isdigit(str[i]))
			count++;
		else if (!std::isspace(str[i]))
			return (false);
		i++;
	}
	if (count >= 4 && count <= 17)
		return (true);
	return (false);
}

//	Checks if the string has trailing whitespaces as such "trailing whitespaces			" <-returns true
bool	findTrailingWs(const std::string &str, std::string::const_iterator it)
{
	while (it != str.end())
	{
		if (!std::isspace(*it))
			return (false);
		it++;
	}
	return (true);
}

// Function will turn this "   			random			string			" into this "random string"
std::string	replaceWhiteSpace(const std::string& str)
{
	std::string					cleanStr;
	std::string::const_iterator	it;
	bool						previousIsWs;

	previousIsWs = false;
	it = str.begin();
	while (it != str.end())
	{
		if (!std::isspace(*it))
			break ;
		it++;
	}
	while (it != str.end())
	{
		if (!std::isspace(*it))
			cleanStr += *it;
		else if (!previousIsWs && !findTrailingWs(str, it))
			cleanStr += ' ';
		previousIsWs = std::isspace(*it);
		it++;
	}
	std::cout << "cleanStr: " << cleanStr << std::endl;
	return (cleanStr);
}

int get_value(std::string prompt, std::string &arg)
{
	std::string	buffer;

	while (1)
	{
		std::cout << "Enter " << prompt << ": " << std::flush;
		getline(std::cin, buffer);
		if (std::cin.fail())
		{
			std::clearerr(stdin);
			std::cin.clear();
			std::cout << "\n";
			break ;
		}
		if (buffer.empty())
		{
			std::cerr << "Error: Field can not be empty, try again" << std::endl;
			continue;
		}
		arg = replaceWhiteSpace(buffer);
		if (prompt != "phone number" && string_is_valid(arg))
			return (0);
		else if (prompt == "phone number" && number_is_valid(arg))
			return (0);
		else
		{
			std::cerr << "Error: Invalid format, try again" << std::endl;
			continue ;
		}
	}
	return (1);
}

int		Contact::create(void)
{
	std::string	buffer;

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
	std::cout << "New contact successfully created" << std::endl;
	return (0);
}

std::string	formatting(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + '.');
	return (str);
}

void	Contact::print_info(size_t index)
{
	std::cout	<< "|" << std::right << std::setw(10) << index
				<< "|" << std::setw(10) << formatting(_FirstName)
				<< "|" << std::setw(10) << formatting(_LastName)
				<< "|" << std::setw(10) << formatting(_Nickname)
				<< "|" << std::endl;
}

void	Contact::print_full_info()
{
	std::cout	<< "First name: " << _FirstName << "\n"
				<< "Last name: " << _LastName << "\n"
				<< "Nickname: " << _Nickname << "\n"
				<< "Phone number: " << _PhoneNumber << "\n"
				<< "Darkest secret: " << _Secret << std::endl;
}
