/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 10:29:32 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/09 19:10:36 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("RobotA");
	ClapTrap b("RobotB");
	ClapTrap *c = &a;
	ClapTrap d("RobotD");
	
	a = b;
	c = &a; // c = RObot B
	a.attack("some random");
	a.takeDamage(20);
	a.beRepaired(2);
	c->attack("itself"); // Robot B can't attack is dead
}
