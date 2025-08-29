/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:11:12 by akdovlet          #+#    #+#             */
/*   Updated: 2025/08/29 21:16:56 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void)
{
	
}

Weapon::Weapon(const std::string& arms) : _type(arms)
{
}

Weapon::~Weapon()
{
}

const std::string &Weapon::getType(void) const
{
	return (_type);
}

void	Weapon::setType(const std::string& type) 
{
	_type = type;
}
