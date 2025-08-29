/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 10:29:46 by akdovlet          #+#    #+#             */
/*   Updated: 2025/08/29 13:48:13 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " constructor called" << std::endl;
}

void	ClapTrap::swap(ClapTrap& other)
{
	unsigned int	tmp;

	_name.swap(other._name);
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
ClapTrap&	ClapTrap::operator=(ClapTrap other)
{
	std::cout << "ClapTrap Copy assignement operator called" << std::endl;
	swap(other);
	return (*this);
}

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
}


ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (!_hitPoints)
	{
		std::cout << "ClapTrap " << _name << " can't attack, is dead" << std::endl;
		return ;
	}
	if (!_energyPoints)
	{
		std::cout << "ClaptTrap " << _name << " can't attack, no energy" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " attacked " << target << " for " << _attackDamage << " damage" << std::endl;
	_energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!_hitPoints)
	{
		std::cout << "ClapTrap " << _name << " is already dead" << std::endl;
		return ;
	}
	if (amount > _hitPoints)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	std::cout << "ClapTrap " << _name << " takes " << amount << " damage, HP is now " << _hitPoints << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!_hitPoints)
	{
		std::cout << "ClapTrap " << _name << " can't be repaired, is dead" << std::endl;
		return ;
	}
	if (!_energyPoints)
	{
		std::cout << "ClaptTrap " << _name << " can't repair, no energy" << std::endl;
		return ;
	}
	_hitPoints += amount;
    std::cout << "ClapTrap " << _name << " repaired " << amount << ", HP now " << _hitPoints << std::endl;
    _energyPoints--;
}

// utility functions

std::string	ClapTrap::getName()
{
	return (_name);
}

unsigned int	ClapTrap::getHP()
{
	return (_hitPoints);
}

unsigned int	ClapTrap::getEP()
{
	return (_energyPoints);
}

unsigned int	ClapTrap::getAD()
{
	return (_attackDamage);
}
