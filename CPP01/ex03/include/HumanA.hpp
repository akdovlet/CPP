/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:20:37 by akdovlet          #+#    #+#             */
/*   Updated: 2025/07/04 17:46:39 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string name, Weapon &type);
		~HumanA();
		void	attack(void);
		
	private:
		HumanA();
		std::string	_name;
		Weapon&	_arms;
};
