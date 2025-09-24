/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:47:07 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/24 12:23:13 by akdovlet         ###   ########.fr       */
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

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter(const char c);
	
	static int getType(const std::string& str);
	static void	printValue(char c);
	static void	printValue(int i);
	static void	printValue(float f);
	static void	printValue(double d);
	static void	convertToChar(const std::string& str);
	static void	convertToInt(const std::string& str);
	static void	convertToFloat(const std::string& str);
	static void	convertToDouble(const std::string& str);

public:
	~ScalarConverter();
	
	ScalarConverter& operator=(const ScalarConverter& other);
	
	static void convert(const std::string str);
};

#endif
