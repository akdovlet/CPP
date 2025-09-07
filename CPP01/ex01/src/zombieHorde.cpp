/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 15:18:09 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/07 17:11:49 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie	*zombieHorde(int N, const std::string &name)
{
	if (N <= 0)
	{
		std::cerr << "Error: Invalid value" << std::endl;
		return (NULL);
	}
	try
	{
		Zombie	*horde = new Zombie[N];
		for (size_t i = 0; i < (size_t)N; i++) {
			horde[i].setName(name);
		}
		return (horde);
	}
	catch (const std::bad_alloc& err)
	{
		std::cerr << "Memory allocation failed: " << err.what() << std::endl;
		return (NULL);
	}
}
