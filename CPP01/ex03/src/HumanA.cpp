/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:21:59 by akdovlet          #+#    #+#             */
/*   Updated: 2025/07/04 17:46:37 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &arms) : _name(name), _arms(arms) {}

HumanA::~HumanA() {}

void	HumanA::attack(void) {
	std::cout << _name << " attacks with their " << _arms.getType() << std::endl;
}
