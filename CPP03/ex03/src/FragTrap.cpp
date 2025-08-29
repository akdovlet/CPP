/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:21:10 by akdovlet          #+#    #+#             */
/*   Updated: 2025/08/29 19:23:08 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	_hitPoints = defaultHitPoints;
	_energyPoints = defaultEnergyPoints;
	_attackDamage = defaultAttackDamage;
	std::cout << "FragTrap default constructor called" <<std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = defaultHitPoints;
	_energyPoints = defaultEnergyPoints;
	_attackDamage = defaultAttackDamage;
	std::cout << "FragTrap " << name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	// _name = other._name;
	// _hitPoints = other._hitPoints;
	// _energyPoints = other._energyPoints;
	// _attackDamage = other._attackDamage;
}

// Using the copy-swap idiom for training and good habits purposes
// Causes the copy constructor to be called implicitely
// exception safety and no conditional if(*this != other)
FragTrap&	FragTrap::operator=(FragTrap other)
{
	std::cout << "FragTrap Copy assignement operator called" << std::endl;
	swap(other);
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " destructor called" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap "<< _name << ": Up top lads!" << std::endl;
}
