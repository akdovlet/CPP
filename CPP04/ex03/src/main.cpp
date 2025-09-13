/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 20:49:22 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/13 19:37:01 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
	std::cout << "Simple Test" << std::endl;
	{	
		Character a("Mason");
		Character b("Yuri");
		Ice			ice;
		Cure		cure;
		AMateria	*tmp;

		tmp = new Ice();
		a.equip(tmp);
		tmp = new Cure();
		a.equip(tmp);
		a.use(0, a);
		a.use(1, b);
		a.use(2, b);
		tmp = new Ice();
		a.equip(tmp);
		a.use(2, a);
	}

	std::cout << "\nMain Test" << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		
		ICharacter* me = new Character("me");
		
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		
		me->use(0, *bob);
		me->use(1, *bob);
		
		delete bob;
		delete me;
		delete src;
	}
	return (0);
}
