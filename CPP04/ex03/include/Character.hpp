/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:51:22 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/04 17:00:03 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

class Character
{
private:
	/* data */
public:
	Character(/* args */);
	Character(const Character& other);
	Character&	operator=(Character other);
	~Character();
};

Character::Character()
{
}

Character::~Character()
{
}


#endif
