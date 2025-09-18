/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:47:07 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/18 23:15:57 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter(const char c);
public:
	~ScalarConverter();
	
	ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other);

	static void convert(const std::string str);
};

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return (*this);
}

double	divide_value(double f, int divisor)
{
	unsigned int pow = 10;

	if (!divisor)
		return (f);
	for (int i = 0; i < divisor; i++)
		pow *= 10;
	return (f / pow);
}

int	check_sign(std::string str, int *i)
{
	int	flip;

	flip = 1;
	if (str[*i] == '-' || str[*i] == '+')
		if (str[(*i)++] == '-')
			flip = -flip;
	return (flip);
}

double	ak_atof(std::string str, int *i)
{
	double	f;
	int		flip;
	int		divisor;

	divisor = 0;
	f = 0;
	while (str[*i] && isspace(str[*i]))
		(*i)++;
	flip = check_sign(str, i);
	while (str[*i])
	{
		if (!isdigit(str[*i]) && str[*i] != '.')
			break ;
		if (divisor)
			divisor++;
		if (str[*i] == '.')
		{
			if (divisor || !isdigit(str[(*i) + 1]))
				break ;
			(*i)++;
			divisor++;
		}
		f = f * 10 + str[(*i)++] - '0';
	}
	return (divide_value(f, divisor) * flip);
}

void	ScalarConverter::convert(const std::string str)
{
	int		i = 0;
	double	n = ak_atof(str, &i);
}

#endif
