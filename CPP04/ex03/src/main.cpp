/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 20:49:22 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/15 00:27:56 by akdovlet         ###   ########.fr       */
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
	#define AK
	#ifdef AK

	std::cout << "Ice and Cure Class Design Test" << std::endl;
	{
		Ice ice;
		Ice ice2 = ice;
		Ice ice3(ice);
		
		AMateria *am;
		
		Character random("random");
		
		std::cout << "ice type: " << ice.getType() << std::endl;
		std::cout << "ice2 type: " << ice2.getType() << std::endl;
		std::cout << "ice3 type: " << ice3.getType() << std::endl;
		
		am = &ice3;
		am->use(random);

		Cure cure;
		Cure cure2 = cure;
		Cure cure3(cure);
		
		am = &cure2;
		
		std::cout << "cure type: " << cure.getType() << std::endl;
		std::cout << "cure2 type: " << cure2.getType() << std::endl;
		std::cout << "cure3 type: " << cure3.getType() << std::endl;

		am->use(random);

		std::cout	<< "\nExpected Output:\n"
					<< "ice type: ice\n"
					<< "ice2 type: ice\n" 
					<< "ice3 type: ice\n" 
					<< "* shoots an ice bolt at random *\n" 
					<< "cure type: cure\n" 
					<< "cure2 type: cure\n" 
					<< "cure3 type: cure\n" 
					<< "* heals random's wounds *" << std::endl; 
	}
	
	std::cout << "\nMateriaSource Memory Management Test" << std::endl;
	{
		IMateriaSource *src = new MateriaSource();
		
		src->learnMateria(new Ice());
		src->learnMateria(new Ice());
		src->learnMateria(new Ice());
		src->learnMateria(new Ice());
		src->learnMateria(new Ice());
		src->learnMateria(new Ice());
		src->learnMateria(new Ice());
		src->learnMateria(new Ice());

		delete src;
		std::cout << "\nExpected:\nShould not leak" << std::endl;
	}

		std::cout << "\nMateriaSource createMateria() Test" << std::endl;
	{
		IMateriaSource	*src = new MateriaSource();
		Character		me("AK");
	
		src->learnMateria(new Ice());
		AMateria *materia = src->createMateria("cure");
		std::cout << materia << std::endl;
		delete src;
		std::cout << "\nExpected Output:\n0" << std::endl;
	}
	
	std::cout << "\nSimple Test" << std::endl;
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

		std::cout	<< "Expected Output:\n"
					<< "* shoots an ice bolt at Mason *\n"
					<< "* heals Yuri's wounds *\n"
					<< "* shoots an ice bolt at Mason *" << std::endl;
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
		
		std::cout	<< "Expected Output:\n"
					<< "* shoots an ice bolt at bob *\n"
					<< "* heals bob's wounds *" << std::endl;
		
		delete bob;
		delete me;
		delete src;
	}
	
	std::cout << "\nFloor Test" << std::endl;
	{
		ICharacter *wizard = new Character("wizard");
		ICharacter *goblin = new Character("goblin");
		ICharacter *knight = new Character("knight");
		
		wizard->equip(new Ice());
		wizard->equip(new Cure());
		
		wizard->use(0, *goblin);
		wizard->use(1, *knight);

		wizard->unequip(0);
		wizard->unequip(0);
		wizard->unequip(1);
		wizard->unequip(1);
		wizard->unequip(2);
		wizard->unequip(3);

		wizard->use(0, *goblin);
		wizard->use(1, *knight);
		wizard->use(2, *knight);
		wizard->use(3, *knight);
		wizard->use(4, *knight);
		wizard->use(5, *knight);
		wizard->use(6, *knight);
		
		wizard->equip(static_cast<Character*>(wizard)->pickUpItem("cure"));
		
		wizard->use(0, *goblin);

		std::cout	<< "Expected Output:\n"
					<< "* shoots an ice bolt at goblin *\n"
					<< "* heals knight's wounds *\n"
					<< "* heals goblin's wounds *" << std::endl;

		delete wizard;
		delete knight;
		delete goblin;
	}

	std::cout << "\nCharacter copy constructor Test" << std::endl;
	{
		Character me("AK");
		
		me.equip(new Ice());
		me.equip(new Cure());
		
		Character random(me);
		
		random.use(0, me);
		random.use(1, me);
		
		std::cout	<< "\nExpected Output:\n"
					<< "* shoots an ice bolt at random *\n"
					<< "* heal's AK's wounds *" << std::endl;
	}

	std::cout << "\nInventory Test" << std::endl;
	{
		Character me("AK");
		
		AMateria	*spell = new Ice();
		me.equip(spell);
		me.equip(spell);
		me.equip(spell);
		me.equip(spell);
		me.equip(spell);
		me.equip(spell);
		
		std::cout << "Expected:\nShould not leak or crash" << std::endl;
	}

	std::cout << "\nCharacter Copy Assignment Operator Test" << std::endl;
	{
		Character me("AK");
		
		me.equip(new Ice());
		me.equip(new Cure());
		
		Character random = me;
		
		random.use(0, me);
		random.use(1, me);

		std::cout	<< "\nExpected Output:\n"
					<< "* shoots an ice bolt at random *\n"
					<< "* heal's AK's wounds *" << std::endl;	
	}
	
	std::cout << "\nCharacter Memory Management Test" << std::endl;
	{
		Character me("AK");
		Character twin("twin");

		me.equip(new Ice());
		me.equip(new Cure());
		me.equip(new Ice());
		me.equip(new Cure());

		me.use(0, twin);
		me.use(1, twin);
		me.use(2, twin);
		me.use(3, twin);

		twin.equip(new Cure());
		twin.equip(new Cure());
		twin.equip(new Cure());
		twin.equip(new Cure());

		me = twin;
		std::cout	<< "me name after assignement: " << me.getName()
					<< "\nme spells after assignement:" << std::endl;
		me.use(0, twin);
		me.use(1, twin);
		me.use(2, twin);
		me.use(3, twin);

		std::cout	<< "\nExpected Output:\n"
					<< "* shoots an ice bolt at twin *\n"
					<< "* heals twin's wounds *\n"
					<< "* shoots an ice bolt at twin *\n"
					<< "* heals twin's wounds *\n"
					<< "me name after assignement: twin\n"
					<< "me spells after assignement:\n"
					<< "* heals twin's wounds *\n"
					<< "* heals twin's wounds *\n"
					<< "* heals twin's wounds *\n"
					<< "* heals twin's wounds *" << std::endl;
	}
	
	std::cout << "\nFloor Permanence Test" << std::endl;
	{
		ICharacter *me = new Character("AK");
		
		me->equip(new Ice());
		me->equip(new Ice());
		me->equip(new Ice());
		me->equip(new Ice());

		me->unequip(0);
		me->unequip(1);
		me->unequip(2);
		me->unequip(3);

		delete me;

		ICharacter *npc = new Character("Joe Schmoe");

		npc->equip(static_cast<Character*>(npc)->pickUpItem("ice"));
		npc->equip(static_cast<Character*>(npc)->pickUpItem("ice"));
		npc->equip(static_cast<Character*>(npc)->pickUpItem("ice"));
		npc->equip(static_cast<Character*>(npc)->pickUpItem("ice"));
		npc->equip(static_cast<Character*>(npc)->pickUpItem("ice"));
		npc->equip(static_cast<Character*>(npc)->pickUpItem("ice"));
		npc->equip(static_cast<Character*>(npc)->pickUpItem("ice"));
		npc->equip(static_cast<Character*>(npc)->pickUpItem("ice"));

		Character random("random");
		npc->use(0, random);
		npc->use(1, random);
		npc->use(2, random);
		npc->use(3, random);
		
		std::cout	<< "\nExpected Output:" << std::endl;
		std::cout	<< "* shoots an ice bolt at random *\n"
					<< "* shoots an ice bolt at random *\n"
					<< "* shoots an ice bolt at random *\n"
					<< "* shoots an ice bolt at random *" << std::endl;
		delete npc;
	}
	#endif
	
	#ifdef SAMY
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		AMateria* Test = new Ice();
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete me;
		delete bob;
		delete Test;

		// MAIN_TESTEUR_BY_SAMY

		ICharacter*	samy = new Character("samy");
		ICharacter* ralph = new Character("ralph");

		AMateria* a = src->createMateria("ice");
		AMateria* b = src->createMateria("ice");
		AMateria* c = src->createMateria("ice");

		AMateria* d = src->createMateria("ice");
		AMateria* e = src->createMateria("cure");
		AMateria* f = src->createMateria("cure");

		// Test fully inventory
		ralph->equip(a);
		ralph->use(0, *samy);
		ralph->equip(b);
		ralph->use(1, *samy);
		ralph->equip(c);
		ralph->use(2, *samy);
		ralph->equip(d);
		ralph->use(3, *samy);

		ralph->equip(e);
		ralph->use(4, *samy);

		// Test equip and unequip
		ralph->unequip(3);
		ralph->use(3, *samy);
		ralph->equip(f);
		ralph->use(3, *samy);

		delete ralph;
		delete samy;
		
		// Test assignement Charactere (deep copy)
		Character louis("louis");
		Character vincent("vincent");

		louis.equip(src->createMateria("ice"));
		vincent.equip(src->createMateria("cure"));

		louis.use(0, vincent);
		vincent.use(0, louis);
		louis = vincent;

		louis.use(0, vincent);
		vincent.use(0, louis);

		louis.use(1, vincent); //<- Slot number 1 is empty

		// Test instance AMateria
		
		// AMateria *no_instance = new AMateria();
		// ICharacter no_instance2;

		delete src;
	}
	#endif
	
	return (0);
}

