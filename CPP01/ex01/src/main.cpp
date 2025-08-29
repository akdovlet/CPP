/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:17:54 by akdovlet          #+#    #+#             */
/*   Updated: 2025/08/29 21:05:02 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	const size_t	N = 10;

	Zombie *Horde = zombieHorde(N, "Jeanne");
	if (!Horde)
		return (1);
	
	for (size_t i = 0; i < N; i++)
		Horde[i].announce();

	delete[] Horde;
}
