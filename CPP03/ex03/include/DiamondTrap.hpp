/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:41:16 by akdovlet          #+#    #+#             */
/*   Updated: 2025/08/29 17:33:00 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H
 
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
	std::string	_name;
public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap& other);
	DiamondTrap& operator=(DiamondTrap other);
	~DiamondTrap();

	void swap(DiamondTrap& other);
	
	void	whoAmI() const;
	void	getValues() const;
	using	ScavTrap::attack;
};

#endif
