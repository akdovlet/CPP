/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 17:33:08 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/12 21:01:32 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"

class Character : public ICharacter
{
private:
	std::string	_name;
	AMateria	*_inventory[4];
public:
	Character();
	Character(const Character& other);
	Character(std::string name);
	~Character();
	Character& operator=(Character other);

	std::string const &getName() const;
	inline void	swap(Character& left, Character &right);
	void	equip(AMateria* m);
	void	unequip(int idx);
	void	use(int idx, ICharacter& target);
};



#endif
