/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 13:33:14 by akdovlet          #+#    #+#             */
/*   Updated: 2025/10/02 16:39:00 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

class Span
{
private:
	std::vector<int>	v1;
	std::size_t	size;
	std::size_t			count;
public:
	
	typedef std::vector<int>::iterator iterator;
	
	Span(unsigned int size = 0);
	Span(const Span& other);
	~Span();
	
	Span&	operator=(Span other);
	
	void	swap(Span& a, Span& b);
	
	void	addNumber(int n);
	int		shortestSpan();
	int		longestSpan();
	
	int		getSize();
	int		getCount();

	iterator begin();
	iterator end();
	
	template<class InputIt>
	std::vector<int>::iterator insert(std::vector<int>::iterator pos, InputIt first, InputIt last)
	{	
		for (std::vector<int>::iterator cit = v1.begin(); cit != pos; cit++)
		{
			if (first != last)
			{
				try
				{
					addNumber(*first);
					first++;
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << '\n';
					return (cit);
				}
			}
			else
				break ;
		}
		return (pos);
	}
	
	class	maxCapacityException : public std::exception
	{
		virtual const char* what() const throw();
	};
	
	class	notEnoughValuesException : public std::exception
	{
		virtual const char* what() const throw();
	};
};

#endif
