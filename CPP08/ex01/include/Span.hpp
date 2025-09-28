/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 13:33:14 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/28 19:42:46 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <iostream>
#include <bits/stdc++.h>

class Span
{
private:
	std::vector<int>	v1;
	std::size_t	size;
	std::size_t			count;
public:
	Span(unsigned int size);
	Span(const Span& other);
	~Span();
	
	Span&	operator=(Span other);
	
	void	swap(Span& a, Span& b);
	
	void	addNumber(int n);
	int		shortestSpan();
	int		longestSpan();
	
	class	maxCapacityException : std::exception
	{
		virtual const char* what() const throw();
	};
	
	class	notEnoughValuesException : std::exception
	{
		virtual const char* what() const throw();
	};
};

#endif
