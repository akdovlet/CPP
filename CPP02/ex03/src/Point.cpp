/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:22:44 by akdovlet          #+#    #+#             */
/*   Updated: 2025/08/27 18:58:50 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point(float x, float y) : _x(x), _y(y)
{
}

Point::Point(const Fixed &x, const Fixed &y) : _x(x), _y(y)
{
}


Point::Point(const Point &other) : _x(other._x), _y(other._y)
{
}

Point&	Point::operator=(const Point &other)
{
	if (this != &other)
		return (*this);
	return (*this);
}

Point::~Point()
{
}

Fixed	Point::getX() const
{
	return (_x);
}

Fixed	Point::getY() const
{
	return (_y);
}
