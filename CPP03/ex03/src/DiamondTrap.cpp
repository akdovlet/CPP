/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:41:14 by akdovlet          #+#    #+#             */
/*   Updated: 2025/08/29 17:58:13 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap()
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	_hitPoints = FragTrap::defaultHitPoints;
	_energyPoints = ScavTrap::defaultEnergyPoints;
	_attackDamage = FragTrap::defaultAttackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), FragTrap(other), ScavTrap(other), _name(other._name)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

void	DiamondTrap::swap(DiamondTrap& other)
{
	unsigned int	tmp;

	_name.swap(other._name);
	ClapTrap::_name.swap(other.ClapTrap::_name);
	tmp = _hitPoints;
	_hitPoints = other._hitPoints;
	other._hitPoints = tmp;
	
	tmp = _energyPoints;
	_energyPoints = other._energyPoints;
	other._energyPoints = tmp;

	tmp = _attackDamage;
	_attackDamage = other._attackDamage;
	other._attackDamage = tmp;
}

// Using the copy-swap idiom for training and good habits purposes
// Causes the copy constructor to be called implicitely
DiamondTrap&	DiamondTrap::operator=(DiamondTrap other)
{
	std::cout << "DiamondTrap Copy assignement operator called" << std::endl;
	swap(other);
	return (*this);
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{
	std::cout << "DiamondTrap " << _name << " constructor called" << std::endl;
	_hitPoints = FragTrap::defaultHitPoints;
	_energyPoints = ScavTrap::defaultEnergyPoints;
	_attackDamage = FragTrap::defaultAttackDamage;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " destructor called" << std::endl;
}

void	DiamondTrap::whoAmI() const
{
	std::cout << "DiamondTrap name: " << _name <<", ClapTrap name: " << ClapTrap::_name << std::endl;
}

void	DiamondTrap::getValues() const
{
	std::cout << _name << std::endl;
	std::cout << _hitPoints << std::endl;
	std::cout << _energyPoints << std::endl;
	std::cout << _attackDamage << std::endl;
}
