/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:59:19 by akdovlet          #+#    #+#             */
/*   Updated: 2025/08/27 17:17:54 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int Fixed::_frac = 8;


// Ctors & Dtor

Fixed::Fixed() : _value(0)
{
}

Fixed::Fixed(const Fixed &cpy) : _value(cpy._value)
{
}

Fixed::Fixed(int const val) : _value(val << _frac)
{
}

Fixed::Fixed(float const val) : _value(static_cast<int>(roundf(val * (1 << _frac))))
{
}

Fixed::~Fixed()
{
}


// Operators

Fixed	&Fixed::operator=(Fixed tmp)
{
	int	tmp_val;

	tmp_val = _value;
	_value = tmp._value;
	tmp._value = tmp_val;
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}

bool	Fixed::operator>(const Fixed& other) const
{
	return (_value > other._value);
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (_value == other._value);
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (_value >= other._value);
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (_value < other._value);
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (_value <= other._value);
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (_value != other._value);
}

Fixed	Fixed::operator+(const Fixed& other) const
{
	Fixed	result;

	result._value = _value + other._value;
	return (result);
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	Fixed	result;

	result._value = _value - other._value;
	return (result);
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	Fixed	result;
	long	long_tmp;
	
	long_tmp = static_cast<long>(_value);
	result._value = static_cast<int>((long_tmp * other._value) >> _frac);
	return result;
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	Fixed	result;
	long	long_tmp;
	
	try
	{
		if (other._value == 0)
			throw std::overflow_error("Divide by zero exception");
	}
	catch(const std::overflow_error& e)
	{
		std::cerr << e.what() << " -> ";
		std::cerr << *this << std::endl;
	}
	long_tmp = static_cast<long>(_value);
	result._value = static_cast<int>((long_tmp << _frac) / other._value);
	return result;
}


// Increment and decrement operators

Fixed&	Fixed::operator++()
{
	++_value;
	return (*this);
}

Fixed&	Fixed::operator--()
{
	--_value;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	cpy(*this);
	++(*this);
	return (cpy);
}

Fixed	Fixed::operator--(int)
{
	Fixed	cpy(*this);
	--(*this);
	return (cpy);
}


// Min max functions

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b) ? a : b;
}

// Utility functions

int		Fixed::getRawBits(void) const
{
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float Fixed::toFloat() const
{
	return (static_cast<float>(_value) / (1 << _frac));
}

int	Fixed::toInt() const
{
	return (_value >> _frac);
}
