/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:57:36 by akdovlet          #+#    #+#             */
/*   Updated: 2025/08/29 14:07:33 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap& other);
    ScavTrap& operator=(ScavTrap other);
    ~ScavTrap();

	void	swap(ScavTrap& other);
    
    void attack(const std::string& target);
    void guardGate();
};

#endif
