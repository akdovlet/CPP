/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 19:42:53 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/29 14:34:44 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

const char*	Span::maxCapacityException::what() const throw()
{
	return ("Error: Can't add more values, maximum capacity reached");
}

const char* Span::notEnoughValuesException::what() const throw()
{
	return ("Error: Not enough values to calculate span");
}

Span::Span(unsigned int n) : v1(n), size(n), count(0)
{
}

Span::~Span()
{
}

Span::Span(const Span& other) : v1(other.v1), size(other.size), count(other.count)
{
}

void	Span::swap(Span& a, Span& b)
{
	using std::swap;
	swap(a.v1, b.v1);
	swap(a.size, b.size);
	swap(a.count, b.count);
}

Span& Span::operator=(Span other)
{
	swap(*this, other);
	return (*this);
}

void	Span::addNumber(int n)
{
	if (++count > size)
		throw maxCapacityException();
	v1[count - 1] = n;
	if (count > 1)
		std::sort(v1.begin(), v1.begin() + count);
}

int	Span::shortestSpan()
{
	if (count <= 1)
		throw notEnoughValuesException();
	
	int	shortestSpan = INT_MAX;

	for(std::vector<int>::iterator it = v1.begin(); it != (v1.end() - 1); it++)
	{
		if (*(it + 1) - *it < shortestSpan)
			shortestSpan = *(it + 1) - *it;
	}
	return (shortestSpan);
}

int	Span::longestSpan()
{
	if (count <= 1)
		throw notEnoughValuesException();
	return (v1[count - 1] - v1[0]);
}

int	Span::getCount()
{
	return (count);
}

int Span::getSize()
{
	return (size);
}
