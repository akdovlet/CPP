/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:10:40 by akdovlet          #+#    #+#             */
/*   Updated: 2025/08/29 21:19:32 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
	public:
		Weapon();
		Weapon(const std::string& arms);
		~Weapon();
		const std::string &getType(void) const;
		void	setType(const std::string& type);
		
	private:
		std::string _type;
};

#endif
