/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:37:36 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/07 17:18:46 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(const std::string& name);
		~HumanB();
		void setWeapon(Weapon &arms);
		void	attack(void);
		
	private:
		std::string _name;
		Weapon *_arms;
};

#endif
