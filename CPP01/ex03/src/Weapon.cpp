/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:11:12 by akdovlet          #+#    #+#             */
/*   Updated: 2025/07/11 18:33:03 by akdovlet         ###   ########.fr       */
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
	return (this->_type);
}

void	Weapon::setType(std::string type) {
	_type = type;
}
