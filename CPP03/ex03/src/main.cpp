/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 10:29:32 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/10 15:30:27 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	{// DiamondTrap d1("Shiny");
		FragTrap	original("Rocky");
		original.attack("your mom");
		original.beRepaired(20);
		FragTrap	YN(original);
		std::cout << YN.getName() << std::endl;
		std::cout << YN.getHP() << std::endl;
		std::cout << YN.getEP() << std::endl;
		std::cout << YN.getAD() << std::endl;
	}

	std::cout << "\n=== Ptr Test" << std::endl;
	{
		ClapTrap *cPtr;
		DiamondTrap diamond("D-Dog");

		cPtr = &diamond;
		cPtr->attack("Nate Dog");
		cPtr->beRepaired(10);
		cPtr->takeDamage(10);
		std::cout << "HP is: " << cPtr->getHP() << std::endl;
		std::cout << "AD is: " << cPtr->getAD() << std::endl;
		std::cout << "EP is: " << cPtr->getEP() << std::endl;
		std::cout << "cPtr name is: " << cPtr->getName() << std::endl;
	}
	
	// d1.getValues();
	return (0);
}
