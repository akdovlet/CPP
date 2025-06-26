/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:25:03 by akdovlet          #+#    #+#             */
/*   Updated: 2025/06/26 20:12:22 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void): _index(0)
{
}

PhoneBook::~PhoneBook(void)
{	
}

void	PhoneBook::increase(void)
{
	PhoneBook::_index++;
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
