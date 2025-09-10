/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:57:44 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/10 12:03:11 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap()
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap default constructor called" <<std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	// _name = other._name;
	// _hitPoints = other._hitPoints;
	// _energyPoints = other._energyPoints;
	// _attackDamage = other._attackDamage;
}

// Using the copy-swap idiom for training and good habits purposes
// Causes the copy constructor to be called implicitely
ScavTrap&	ScavTrap::operator=(ScavTrap other)
{
	std::cout << "ScavTrap Copy assignement operator called" << std::endl;
	swap(other);
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (!_hitPoints)
	{
		std::cout << "ScavTrap " << _name << " can't attack, is dead" << std::endl;
		return ;
	}
	if (!_energyPoints)
	{
		std::cout << "ScavTrap " << _name << " can't attack, no energy" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << _name << " attacked " << target << " for " << _attackDamage << " damage" << std::endl;
	_energyPoints--;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in Gate Keeper mode" << std::endl;
}
