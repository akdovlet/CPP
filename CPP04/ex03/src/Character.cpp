/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 19:33:42 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/12 21:37:18 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : ICharacter(), _name("anon")
{
}

Character::Character(const Character& other) : ICharacter(other), _name(other._name)
{
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
		{
			delete _inventory[i];
			_inventory[i] = other._inventory[i]->clone();
		}
	}
}

Character::Character(std::string name) : _name(name)
{
}

inline void	Character::swap(Character& left, Character& right)
{
	using std::swap;
	swap(left._inventory, right._inventory);
}

Character&	Character::operator=(Character other)
{
	swap(*this, other);
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		delete _inventory[i];
	}
}

void	unequip(int idx);
void	use(int idx, ICharacter& target);

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m->clone();
			delete m;
		}
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (_inventory[idx])
		_inventory[idx]->use(target);
}

std::string const &Character::getName() const
{
	
}
