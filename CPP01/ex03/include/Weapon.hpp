/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:10:40 by akdovlet          #+#    #+#             */
/*   Updated: 2025/07/04 17:37:26 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Weapon
{
	public:
		Weapon();
		Weapon(std::string arms);
		~Weapon();
		const std::string &getType(void);
		void	setType(std::string type);
		
	private:
		std::string _type;
};
