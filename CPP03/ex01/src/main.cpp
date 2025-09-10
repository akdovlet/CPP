/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 10:29:32 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/10 12:16:34 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

int main()
{
	ClapTrap *cPtr;
	ClapTrap *cPtr2;
	ScavTrap a("ChadScav");
	ScavTrap b;

	b = a;
	cPtr = &a;
	cPtr2 = new ScavTrap("Dynamic");
	std::cout << b.getHP() << std::endl;
	std::cout << b.getEP() << std::endl;
	std::cout << b.getAD() << std::endl;

	b.attack("some random");
	b.beRepaired(100);
	
	cPtr->attack("ur momma");
	std::cout << b.getHP() << std::endl;
	delete cPtr2;
	return (0);
}
