/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:19:02 by akdovlet          #+#    #+#             */
/*   Updated: 2025/08/29 20:57:48 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>
#include <new>

class	Zombie
{
	public:
	
		Zombie();
		Zombie(const std::string &name);
		~Zombie(void);
		void	announce(void) const;

		void setName(const std::string&);
	
	private:

		std::string	_name;
};

Zombie	*zombieHorde(int N, const std::string &name);

#endif
