/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:27:41 by akdovlet          #+#    #+#             */
/*   Updated: 2025/07/11 22:11:23 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdint.h>

class Fixed
{
private:
	uint32_t				_number;
	static const uint32_t	_fraction;
public:
	Fixed();
	Fixed(Fixed &);
	~Fixed();
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

