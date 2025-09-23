/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:47:07 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/23 19:34:10 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <sstream>

#define CHAR 0
#define INT 1
#define FLOAT 2
#define DOUBLE 3
#define UNKNOWN 4

typedef struct s_value
{
	int	type;
	union uu
	{
		char	c;
		int		i;
		float	f;
		double	d;
	} x;
} value;


class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter(const char c);
public:
	~ScalarConverter();
	
	ScalarConverter& operator=(const ScalarConverter& other);

	static void	getChar(const std::string& str);
	static void	toInt(const std::string& str);
	static void	toLong(const std::string& str);
	static void	toDouble(const std::string& str);
	
	static void convert(const std::string str);
};

#endif
