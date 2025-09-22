/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 16:20:36 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/22 20:10:48 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <climits>
#include <iomanip>

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

void	ScalarConverter::toChar(const std::string& str)
{
	unsigned char	c;
	unsigned int	val;
	std::stringstream sstr;

	sstr << str;
	std::cout << "char: ";
	if (str.length() == 1)
	{
		sstr >> c;
		if (!isdigit(c) && isprint(c))
			std::cout << "'" << c << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	else
	{
		if (isdigit(str[0]))
		{
			sstr >> val;
			if (isprint(val))
				std::cout << "'" << static_cast<unsigned char>(val) << "'" << std::endl;
			else
				std::cout << "Non displayable" << std::endl;
		}
		else
			std::cout << "Impossible" << std::endl;
	}
}

void	ScalarConverter::toInt(const std::string& str)
{
	std::stringstream	sstr;
	double				n;
	
	sstr << str;
	sstr >> n;

	std::cout << "int: ";
	if (n > INT_MAX || n < INT_MIN)
		std::cout << "Impossible" << std::endl;
	else
		std::cout << static_cast<int>(n) << std::endl;
}

int		getType(const std::string& str)
{
	int	i = 0;
	bool	hasDigit;

	if (str.length() == 1 && !isdigit(str[0]))
		return (CHAR);
	while (str[i] && isspace(str[i]))
		i++;
	while (str[i] && isdigit(str[i]))
	{
		hasDigit = true;
		i++;
	}
	if (hasDigit && (!str[i] || str[i] != '.'))
		return (INT);
	if (str[i++] == '.')
	{
		while (str[i] && isdigit(str[i]))
	}
}

void	ScalarConverter::convert(const std::string str)
{
	if (str.empty())
	{
		std::cout << "Empty string" << std::endl;
		return ;
	}

	toChar(str);
	toInt(str);

}
