/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:59:19 by akdovlet          #+#    #+#             */
/*   Updated: 2025/08/27 16:05:58 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int Fixed::_frac = 8;

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &cpy) : _value(cpy._value)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(int const val) : _value(val << _frac)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const val) : _value(static_cast<int>(roundf(val * (1 << _frac))))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed	&Fixed::operator=(Fixed tmp)
{
	int	tmp_val;

	std::cout << "Copy assignment operator called" << std::endl;
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

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
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
