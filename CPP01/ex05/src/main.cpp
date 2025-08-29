/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:31:34 by akdovlet          #+#    #+#             */
/*   Updated: 2025/08/29 22:35:41 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Usage: " << av[0] << " <level> (DEBUG/INFO/WARNING/ERROR)" << std::endl;
		return (1);
	}
	
	Harl	harl;
	harl.complain(av[1]);
}
