/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 10:29:32 by akdovlet          #+#    #+#             */
/*   Updated: 2025/08/29 14:18:42 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

int main()
{
	ScavTrap a("ChadScav");
	ScavTrap b;

	b = a;

	std::cout << b.getHP() << std::endl;
	std::cout << b.getEP() << std::endl;
	std::cout << b.getAD() << std::endl;

	b.attack("some random");
	b.beRepaired(100);
	std::cout << b.getHP() << std::endl;

	return (0);
}
