/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 10:29:32 by akdovlet          #+#    #+#             */
/*   Updated: 2025/08/29 17:45:18 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("RobotA");
	ClapTrap b("RobotB");
	ClapTrap c("RobotC");
	ClapTrap d("RobotD");
	a = b;
	c = c;
	a.attack("some random");
	a.takeDamage(20);
	a.beRepaired(2);
}
