/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 10:29:32 by akdovlet          #+#    #+#             */
/*   Updated: 2025/08/29 14:38:55 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ScavTrap a("ChadScav");
	ScavTrap b;
	FragTrap c;

	b = a;

	std::cout << b.getHP() << std::endl;
	std::cout << b.getEP() << std::endl;
	std::cout << b.getAD() << std::endl;

	b.attack("some random");
	b.beRepaired(100);
	std::cout << b.getHP() << std::endl;

	std::cout << c.getHP() << std::endl;
	std::cout << c.getEP() << std::endl;
	std::cout << c.getAD() << std::endl;
	c.highFivesGuys();
	c.attack("your moma");

	return (0);
}
