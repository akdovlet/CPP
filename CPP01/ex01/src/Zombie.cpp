/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:23:48 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/07 17:11:57 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

void	Zombie::announce(void) const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie() : _name("")
{
}

Zombie::Zombie(const std::string &name) : _name(name) {}

Zombie::~Zombie(void)
{
	std::cout << _name << ": wasted" << std::endl;
}

void Zombie::setName(const std::string& name) {
	_name = name;
}
