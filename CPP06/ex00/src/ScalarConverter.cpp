/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 16:20:36 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/24 16:04:17 by akdovlet         ###   ########.fr       */
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
int		ScalarConverter::getType(const std::string& str)
{
	int		i = 0;
	bool	hasDi
	}git = false;
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

void	ScalarConverter::printValue(char c)
{
	if (isprint(c))
		std::cout << "char: " << "'" << c << "'" << std::endl;
	else
		std::cout << "char: non displayable" << std::endl;
}

void	ScalarConverter::printValue(int i)
{
	std::cout << "int: " << i << std::endl;
}

void	ScalarConverter::printValue(float f)
{
	if (f - (int)f != 0 || f >= 1000000)
		std::cout << "float: " << f << "f" << std::endl;
	else
		std::cout << "float: " << f << ".0f" << std::endl;
}

void	ScalarConverter::printValue(double d)
{
	if (d - (int)d != 0 || d >= 1000000)
		std::cout << "double: " << d << std::endl;
	else
		std::cout << "double: " << d << ".0" << std::endl;
}

void	ScalarConverter::convertToChar(const std::string& str)
{
	char c;
	
	if (str.length() == 1)
		c = str[0];
	else
		c = str[1];
	printValue(c);
	printValue(static_cast<int>(c));
	printValue(static_cast<float>(c));
	printValue(static_cast<double>(c));
}

void	ScalarConverter::convertToInt(const std::string& str)
{
	std::stringstream	sstr;
	double				n;
	int					i;

	sstr << str;
	sstr >> n;
	i = static_cast<int>(n);
	printValue(static_cast<char>(i));
	if (n > INT_MAX || n < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		printValue(i);
	printValue(static_cast<float>(i));
	printValue(static_cast<double>(i));
}

void	ScalarConverter::convertToFloat(const std::string& str)
{
	std::stringstream	sstr;
	double				n;

	sstr << str;
	sstr >> n;
	if (str.find("nanf") != str.npos)
	{
		std::cout << "char: impossible" << std::endl; 
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (str.find("-inff") != str.npos)
	{
		std::cout << "char: impossible" << std::endl; 
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else if (str.find("inff") != str.npos)
	{
		std::cout << "char: impossible" << std::endl; 
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
	}
	else
	{
		float f = static_cast<float>(n);
		printValue(static_cast<char>(f));
		printValue(static_cast<int>(f));
		printValue(f);
		printValue(static_cast<double>(f));
	}
}

void	ScalarConverter::convertToDouble(const std::string& str)
{
	std::stringstream	sstr;
	double				n;

	sstr << str;
	sstr >> n;
	if (str.find("nan") != str.npos)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (str.find("-inf") != str.npos)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else if (str.find("inf") != str.npos)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
	}
	else
	{
		printValue(static_cast<char>(n));
		printValue(static_cast<int>(n));
		printValue(static_cast<float>(n));
		printValue(n);
	}
}

void	ScalarConverter::convert(const std::string str)
{
	if (str.empty())
	{
		std::cout << "Empty string" << std::endl;
		return ;
	}

	// std::cout << std::fixed << std::setprecision(2);
	switch (getType(str))
	{
	case CHAR:
		// std::cout << "Type char" << std::endl;
		convertToChar(str);
		break;
	case INT:
		// std::cout << "Type int" << std::endl;
		convertToInt(str);
		break ;
	case FLOAT:
		// std::cout << "Type float" << std::endl;
		convertToFloat(str);
		break;
	case DOUBLE:
		// std::cout << "Type double" << std::endl;
		convertToDouble(str);
		break ;
	default:
		std::cout << "Invalid type" << std::endl;
		break;
	}

}
