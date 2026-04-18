/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:02:31 by akdovlet          #+#    #+#             */
/*   Updated: 2026/04/18 02:36:00 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <stack>

bool	isoperator(char c)
{
	if (c == '+' || c == '-' || c == '/' || c == '*')
		return (true);
	return (false);
}

bool isnumber(char c, char d)
{
	if (isdigit(c) && !isdigit(d) && c >= '0' && c <= '9')
		return (true);
	return (false);
}

int	ak_atoi(const char *str, int& i)
{
	int value = str[i] - '0';
	i++;
	return (value);
}

void	calculate(std::stack<int>& stack, char op)
{
	if (stack.size() < 2)
		throw std::runtime_error("Syntax error");
	
	int	v1, v2;
	v1 = stack.top(); stack.pop();
	v2 = stack.top(); stack.pop();

	if ((v1 == 0 || v2 == 0) && op == '/')
		throw std::runtime_error("Division by zero");

	switch (op)
	{
	case '+':
		stack.push(v1 + v2);
		break;
	case '-':
		stack.push(v2 - v1);
		break ;
	case '*':
		stack.push(v1 * v2);
		break ;
	case '/':
		stack.push(v2 / v1);
		break ;
	default:
		break;
	}
}

void	rpnCalculator(const char* str)
{
	int	i = 0;
	std::stack<int> stack;
	
	while (str[i])
	{
		if (isnumber(str[i], str[i + 1]))
			stack.push(ak_atoi(str, i));
		else if (isoperator(str[i]))
			calculate(stack, str[i++]);
		else if (isspace(str[i]))
			i++;
		else
			throw std::runtime_error("Invalid token");
	}

	if (!stack.size())
		throw std::runtime_error("Syntax error");
	int result = stack.top(); stack.pop();
	
	if (stack.size())
		throw std::runtime_error("Syntax error");
	std::cout << result << std::endl;
}
