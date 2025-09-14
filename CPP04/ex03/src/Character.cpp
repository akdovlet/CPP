/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 19:33:42 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/14 23:44:55 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Floor Character::floor;

Character::Character() : ICharacter(), _name("Anon")
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character& other) : ICharacter(other), _name(other._name)
{
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
		{
			_inventory[i] = other._inventory[i]->clone();
		}
		else
			_inventory[i] = NULL;
	}
}

Character::Character(std::string name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

inline void	Character::swap(Character& left, Character& right)
{
	using std::swap;
	swap(left._inventory, right._inventory);
	swap(left._name, right._name);
}

Character&	Character::operator=(Character other)
{
	swap(*this, other);
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (_inventory[i])
			delete _inventory[i];
}

void	Character::equip(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (m == _inventory[i])
		{
			std::cout << "Item already equiped" << std::endl;
			return ;
		}
		if (!_inventory[i])
		{
			_inventory[i] = m;
			return ;
		}
	}
	std::cout << "Inventory full: Materia lost" << std::endl;
	delete m;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && _inventory[idx])
		_inventory[idx]->use(target);
}

std::string const &Character::getName() const
{
	return (_name);
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && _inventory[idx])
	{
		floor.insertAtBeginning(&floor._head, _inventory[idx]);
		_inventory[idx] = NULL;
	}
}

AMateria*	Character::pickUpItem(const std::string type)
{
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
			return (floor.pickUpItem(type));
	}
	return (NULL);
}

