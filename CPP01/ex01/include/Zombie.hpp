/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:19:02 by akdovlet          #+#    #+#             */
/*   Updated: 2025/07/04 15:40:12 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <new>

class	Zombie
{
	public:
	
		Zombie();
		Zombie(std::string name);
		~Zombie(void);
		void	announce(void);

		void setName(const std::string&);
	
	private:

		std::string	_name;
};

Zombie	*zombieHorde(int N, std::string name);
