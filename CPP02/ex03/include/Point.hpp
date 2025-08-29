/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:23:10 by akdovlet          #+#    #+#             */
/*   Updated: 2025/08/27 22:07:33 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <stdint.h>
#include <cmath>

class Point
{
private:
	Fixed const _x;
	Fixed const _y;
public:
	Point();
	Point(float x, float y);
	Point(const Fixed &x, const Fixed &y);
	Point(const Point &other);
	~Point();
	Fixed	getX() const;
	Fixed	getY() const;
	Point&	operator=(const Point &tmp);
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);
