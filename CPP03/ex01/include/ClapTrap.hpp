/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 10:29:29 by akdovlet          #+#    #+#             */
/*   Updated: 2025/08/29 18:49:57 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <string>
#include <iostream>

class ClapTrap
{
protected:
	std::string				_name;
	unsigned int			_hitPoints;
	unsigned int			_energyPoints;
	unsigned int			_attackDamage;
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& other);
	ClapTrap&	operator=(ClapTrap other);
	virtual		~ClapTrap();

	void		swap(ClapTrap& other);
	
	virtual void	attack(const std::string& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);

	std::string		getName();
	unsigned int	getHP();
	unsigned int	getEP();
	unsigned int	getAD();
};

#endif
