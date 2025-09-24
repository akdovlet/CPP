/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:23:38 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/24 16:59:55 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data()
{
}

Data::Data(const std::string& str) : _value(str)
{
}

Data::Data(const Data& other) : _value(other._value)
{
}

Data& Data::operator=(const Data& other)
{
	_value = other._value;
	return (*this);
}

Data::~Data()
{
}

std::string	Data::getValue()
{
	return (_value);
}
