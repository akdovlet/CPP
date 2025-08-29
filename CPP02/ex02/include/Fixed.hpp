/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:27:41 by akdovlet          #+#    #+#             */
/*   Updated: 2025/08/27 16:17:27 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdint.h>
#include <cmath>

class Fixed
{
private:
	int					_value;
	static const int	_frac;
public:
	Fixed();
	Fixed(const int);
	Fixed(const float);
	Fixed(const Fixed& cpy);
	~Fixed();

	Fixed&	operator=(Fixed tmp);

	bool	operator>(const Fixed& other) const;
	bool	operator<(const Fixed& other) const;
	bool	operator>=(const Fixed& other) const;
	bool	operator<=(const Fixed& other) const;
	bool	operator==(const Fixed& other) const;
	bool	operator!=(const Fixed& other) const;
	
	Fixed	operator+(const Fixed& other) const;
	Fixed	operator-(const Fixed& other) const;
	Fixed	operator*(const Fixed& other) const;
	Fixed	operator/(const Fixed& other) const;
	
	Fixed&	operator++();    
	Fixed	operator++(int);
	Fixed&	operator--();
	Fixed	operator--(int);

	static Fixed&		min(Fixed& a, Fixed& b);
	static const Fixed&	min(const Fixed& a, const Fixed& b);
	static Fixed&		max(Fixed& a, Fixed& b);
	static const Fixed&	max(const Fixed& a, const Fixed& b);

	float	toFloat(void) const;
	int		toInt(void) const;

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed);
