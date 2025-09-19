/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 16:20:36 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/19 17:01:34 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return (*this);
}

void	ScalarConverter::convert(const std::string str)
{
	if (str.empty())
	{
		std::cout << "Empty string" << std::endl;
		return ;
	}
	std::stringstream	sstr;
	double				n;
	sstr << str;
	sstr >> n;

	std::cout << static_cast<char>(n) << std::endl;
	std::cout << static_cast<int>(n) << std::endl;
	std::cout << static_cast<long>(n) << std::endl;
	std::cout << n << std::endl;
}
