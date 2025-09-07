/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:01:16 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/07 17:35:12 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"
#include <string>
#include <iostream>

HumanB::HumanB(const std::string& name) : _name(name), _arms(NULL) 
{
}

HumanB::~HumanB() 
{
}

void HumanB::setWeapon(Weapon &arms)
{
	_arms = &arms;
}

void	HumanB::attack(void) 
{
	if (!_arms) {
		std::cout << _name << " attacks with their bare fist" << std::endl;
		return ;
	}
	std::cout << _name << " attacks with their " << _arms->getType() << std::endl;
}
