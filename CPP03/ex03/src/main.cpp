/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 10:29:32 by akdovlet          #+#    #+#             */
/*   Updated: 2025/08/29 19:32:22 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	// DiamondTrap d1("Shiny");
	FragTrap	original("Rocky");
	original.attack("your mom");
	original.beRepaired(20);
	FragTrap	YN(original);
	std::cout << YN.getName() << std::endl;
	std::cout << YN.getHP() << std::endl;
	std::cout << YN.getEP() << std::endl;
	std::cout << YN.getAD() << std::endl;

	
	// d1.getValues();
	return (0);
}
