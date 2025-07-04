/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:11:12 by akdovlet          #+#    #+#             */
/*   Updated: 2025/07/04 17:43:27 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void)
{
	
}

Weapon::Weapon(std::string arms)
{
	_type = arms;
}

Weapon::~Weapon()
{
}

const std::string &Weapon::getType(void) {
	return (_type);
}

void	Weapon::setType(std::string type) {
	_type = type;
}
