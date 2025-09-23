/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:47:07 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/23 13:12:00 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <sstream>

#define CHAR 0
#define CHARQ 1
#define INT 2
#define FLOAT 3
#define DOUBLE 4
#define UNKNOWN 5

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter(const char c);
public:
	~ScalarConverter();
	
	ScalarConverter& operator=(const ScalarConverter& other);

	static void	toChar(const std::string& str);
	static void	toInt(const std::string& str);
	static void	toLong(const std::string& str);
	static void	toDouble(const std::string& str);
	
	static void convert(const std::string str);
};

#endif
