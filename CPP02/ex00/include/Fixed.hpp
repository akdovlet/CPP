/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:27:41 by akdovlet          #+#    #+#             */
/*   Updated: 2025/08/29 23:10:41 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
private:
	int					_value;
	static const int	_frac;
public:
	Fixed();
	Fixed(const Fixed &cpy);
	Fixed	&operator=(const Fixed &fixed);
	~Fixed();
	
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif
