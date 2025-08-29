/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:25:03 by akdovlet          #+#    #+#             */
/*   Updated: 2025/08/29 20:20:31 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iomanip>
#include <cstdio>
#include <string>

PhoneBook::PhoneBook(void): _index(0), _count(0)
{
}

PhoneBook::~PhoneBook(void)
{
}

void	PhoneBook::increase(void)
{
	_index++;
	_count++;
}

size_t	PhoneBook::get_index(void)
{
	return _index;
}

size_t PhoneBook::get_count(void)
{
	return _count;
}

void PhoneBook::add()
{
	Contact	tmp;

	if (!tmp.create())
	{
		PhoneBook::WhitePages[PhoneBook::_index % 8] = tmp;
		PhoneBook::increase();
	}
}

bool	valid_number(std::string &str)
{
	size_t	i;

	i = 0;
	while (i < str.size() && std::isspace(str[i]))
		i++;
	if (i == str.size() || str.size() - i > 2)
		return (false);
	while (i < str.size())
	{
		if (!std::isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

int		ak_stoi(std::string &str)
{
	size_t	i;
	int	result;

	i = 0;
	result = 0;
	while (i < str.size())
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

bool	recover_index(size_t &index)
{
	std::string	buffer;

	while (1)
	{
		std::cout << "Enter index: " << std::flush;
		getline(std::cin, buffer);
		if (std::cin.fail())
		{
			std::clearerr(stdin);
			std::cin.clear();
			std::cout << std::endl;
			break ;
		}
		if (valid_number(buffer))
		{
			index = ak_stoi(buffer);
			return (true);
		}
		else
			std::cerr << "Error: Invalid entry, try again" << std::endl;
	}
	return (false);
}

void PhoneBook::search()
{
	size_t	index;

	if (!_count)
	{
		std::cout << "No entry" << std::endl;
		return ;
	}
	std::cout	<< std::right << "|" << std::setw(10) << "index" << "|"
				<< std::setw(10) << "First Name" << "|"
				<< std::setw(10) << "Last Name" << "|" 
				<< std::setw(10) << "Nickname" << "|" << std::endl;
	for (size_t i = 0; i < _count && i < 8; i++)
		WhitePages[i].print_info(i + 1);
	if (recover_index(index))
	{
		if (index - 1 < 8 && index - 1 < _count)
			WhitePages[index - 1].print_full_info();
		else
			std::cout << "No such entry" << std::endl;		
	}
}
