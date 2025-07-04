/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:19:02 by akdovlet          #+#    #+#             */
/*   Updated: 2025/07/04 15:30:51 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class	Zombie
{
	public:
	
		Zombie();
		Zombie(std::string name);
		~Zombie(void);
		void	announce(void);
	
	private:

		std::string	_name;
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);
