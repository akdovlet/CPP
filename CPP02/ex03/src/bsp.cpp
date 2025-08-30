/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:22:53 by akdovlet          #+#    #+#             */
/*   Updated: 2025/08/30 00:24:12 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed	cross(const Point &a, const Point &b, const Point &c)
{
	return ((b.getX() - a.getX()) * (c.getY() - a.getY()) -
			 (c.getX() - a.getX()) * (b.getY() - a.getY()));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	crossABC = cross(a, b, c);
	if (crossABC == Fixed(0))
		return (false);
	
	Fixed crossPBC = cross(point, b, c);
	Fixed crossPCA = cross(point, c, a);
	Fixed crossPAB = cross(point, a, b);
	
	if ((crossPBC > Fixed(0)) != (crossABC > Fixed(0)) ||
		(crossPCA > Fixed(0)) != (crossABC > Fixed(0)) ||
		(crossPAB > Fixed(0)) != (crossABC > Fixed(0)))
		return (false);
	
	if (crossPBC.abs() == Fixed(0) || crossPCA.abs() == Fixed(0) || crossPAB.abs() == Fixed(0))
		return false;
	
	Fixed sumABS = crossPBC.abs() + crossPCA.abs() + crossPAB.abs();
	return (sumABS - crossABC.abs() < Fixed(0.0039f));
}
