/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 16:20:36 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/23 21:12:43 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <climits>
#include <limits>
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

//Figure out which type we're dealing with by process of elimination
int		getType(const std::string& str)
{
	int		i = 0;
	bool	hasDigit = false;
	bool	hasFractional = false;

	if (str.length() == 1 && !isdigit(str[0]))
		return (CHAR);
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		return (CHAR);
	while (str[i] && isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str.compare(i, 4, "inff") || !str.compare(i, 4, "nanf"))
		return (FLOAT);
	if (!str.compare(i, 3, "inf") || !str.compare(i, 3, "nan"))
		return (DOUBLE);
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
		{
			hasFractional = true;
			i++;
		}
		if (hasDigit || hasFractional)
		{
			if (str[i] == 'f')
				return (FLOAT);
			return (DOUBLE);
		}
	}
	return (UNKNOWN);
}


void	print(char c)
{
	std::cout << "char: ";
	if (isprint(c))
		std::cout << "'" << c << "'" << std::endl;
	else if (c < 0)
		std::cout << "impossible" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

void	print(int i)
{
	std::cout << "int: " << i << std::endl;
}

void	print(int i, const std::string& str)
{
	(void)i;
	std::cout << "int: " << str << std::endl;
}

void	print(float f, const std::string& str)
{
	(void)f;
	std::cout << "float: " << str << std::endl;
}

void	convertTo(char c, const std::string& str)
{
	if (str.length() == 1)
		c = str[0];
	else if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		c = str[1];
	print(c);
	print(static_cast<int>(c));
}

void	convertTo(int i, const std::string& str)
{
	std::stringstream	sstr;
	double				n;

	sstr << str;
	sstr >> n;
	i = static_cast<int>(n);
	print(static_cast<char>(i));
	if (n > INT_MAX || n < INT_MIN)
		print(i, "impossible");
	else
		print(i);
}

void	convertTo(float f, const std::string& str)
{
	std::stringstream	sstr;
	double				n;

	sstr << str;
	sstr >> n;
	if (str.find("nanf") != str.npos)
	{
		print((char) -1);
		print(1, "impossible");
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (str.find("-inff") != str.npos)
	{
		print((char) -1);
		print(1, "impossible");
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else if (str.find("inff") != str.npos)
	{
		print((char) -1);
		print(1, "impossible");
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
	}
	else
	{
		f = static_cast<float>(n);
		print(static_cast<char>(f));
		print(static_cast<int>(f));		
	}
	// if (n < std::numeric_limits<float>::max() || n > std::numeric_limits<float>::min())
	// 	print(f, "impossible");
	std::cout << "float: " << f << "f" << std::endl;
}

void	ScalarConverter::convert(const std::string str)
{
	if (str.empty())
	{
		std::cout << "Empty string" << std::endl;
		return ;
	}

	switch (getType(str))
	{
	case CHAR:
		std::cout << "Type char" << std::endl;
		convertTo((char)CHAR, str);
		break;
	case INT:
		convertTo((int)INT, str);
		std::cout << "Type int" << std::endl;
		break ;
	case FLOAT:
		convertTo((float)FLOAT, str);
		std::cout << "Type float" << std::endl;
		break;
	case DOUBLE:
		std::cout << "Type double" << std::endl;
		break ;
	default:
		std::cout << "Invalid type" << std::endl;
		break;
	}

}
