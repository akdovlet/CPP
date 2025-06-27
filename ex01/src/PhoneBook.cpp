/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:25:03 by akdovlet          #+#    #+#             */
/*   Updated: 2025/06/27 18:09:17 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iomanip>

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

void PhoneBook::search()
{
	std::cout	<< std::right << "|" << std::setw(10) << "index" << "|"
				<< std::right << std::setw(10) << "First Name" << "|"
				<< std::right << std::setw(10) << "Last Name" << "|" << std::endl;
	for (size_t i = 0; i < _count && i < 8; i++)
		WhitePages[i].print_info();
}
