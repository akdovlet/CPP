/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 16:20:36 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/25 10:23:18 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <climits>
#include <limits>
#include <iomanip>
#include <cmath>

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

bool	checkChar(const std::string& str, int *i)
{
	while (str[*i] && isspace(str[*i]))
		(*i)++;
	if (str[*i] && str[*i] == '\'' && str[*i + 1] && str[*i + 2] == '\'')
	{
		*i += 3;
		while (str[*i])
		{
			if (str[*i] && !isspace(str[*i]))
				return (false);
			(*i)++;
		}
		return (true);
	}
	if (str[*i] && !isdigit(str[*i]))
	{
		(*i)++;
		while (str[*i])
		{
			if (str[*i] && !isspace(str[*i]))
				return (false);
			(*i)++;
		}
		return (true);
	}
	return (false);
}

//Figure out which type we're dealing with by process of elimination
int		ScalarConverter::getType(const std::string& str)
{
	int		i = 0;
	bool	hasDigit = false;
	bool	hasFractional = false;

	if (checkChar(str, &i))
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
	{
		std::stringstream	sstr;
		int					number;

		sstr << str;
		sstr >> number;
		if (sstr.fail())
			return (DOUBLE);
		return (INT);
	}
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
	if (f - (int)f != 0 || f >= 1000000 || f <= -1000000)
		std::cout << "float: " << f << "f" << std::endl;
	else
		std::cout << "float: " << f << ".0f" << std::endl;
}

void	ScalarConverter::printValue(double d)
{
	if (d - (int)d != 0 || d >= 1000000 || d <= -1000000)
		std::cout << "double: " << d << std::endl;
	else
		std::cout << "double: " << d << ".0" << std::endl;
}

char	findChar(const std::string& str)
{
	int i = 0;

	if (str.length() == 1)
		return (str[0]);
	while (str[i] && isspace(str[i]))
		i++;
	if (str[i] == '\'' && str[i + 1] && str[i + 2] == '\'')
		return (str[i + 1]);
	return (str[i]);
}

void	ScalarConverter::convertToChar(const std::string& str)
{
	char c = findChar(str);
	
	printValue(c);
	printValue(static_cast<int>(c));
	printValue(static_cast<float>(c));
	printValue(static_cast<double>(c));
}

void	ScalarConverter::convertToInt(const std::string& str)
{
	std::stringstream	sstr;
	int					i;

	sstr << str;
	sstr >> i;
	if (sstr.fail())
	{
		std::cout	<< "char: impossible\n"
					<< "int: impossible\n"
					<< "float: impossible\n"
					<< "double: impossible" << std::endl;
		return ;
	}
	if (i > 0 && i <= 127)
		printValue(static_cast<char>(i));
	else
		std::cout << "char: impossible" << std::endl;
	printValue(i);
	printValue(static_cast<float>(i));
	printValue(static_cast<double>(i));
}

void	ScalarConverter::convertToFloat(const std::string& str)
{
	std::stringstream	sstr;
	float				f;

	sstr << str;
	sstr >> f;
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
		if (!sstr.fail() && (f > 0 && f <= 127))
			printValue(static_cast<char>(f));
		else
			std::cout << "char: impossible" << std::endl;
		if (sstr.fail() || f > (float)INT_MAX || f < (float)INT_MIN)
			std::cout << "int: impossible" << std::endl;
		else
			printValue(static_cast<int>(f));
		if (sstr.fail())
		{
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;	
		}
		else
		{
			printValue(f);
			printValue(static_cast<double>(f));
		}
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
		std::cout	<< "char: impossible\n" 
					<< "int: impossible\n" 
					<< "float: nanf\n" 
					<< "double: nan" << std::endl;
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
		if ((n > 0 && n <= 127) && !sstr.fail())
			printValue(static_cast<char>(n));
		else
			std::cout << "char: impossible" << std::endl;
		if (n > (double)INT_MAX || n < (double)INT_MIN || sstr.fail())
			std::cout << "int: impossible" << std::endl;
		else
			printValue(static_cast<int>(n));
		if (std::isinf(static_cast<float>(n)) || sstr.fail())
			std::cout << "float: impossible" << std::endl;
		else
			printValue(static_cast<float>(n));
		if (sstr.fail())
			std::cout << "double: impossible" << std::endl;
		else
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
		std::cout	<< "char: impossible\n"
					<< "int: impossible\n"
					<< "float: impossible\n"
					<< "double: impossible" << std::endl;
		break;
	}
}
