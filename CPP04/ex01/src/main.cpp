/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:31:05 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/11 18:53:57 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

#include <iostream>

int main()
{
	{
		std::cout << "=== Test sound ===" << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		j->makeSound(); // Dog sound
		i->makeSound(); //will output the cat sound!
		meta->makeSound(); // Animal sound
		
		delete meta;
		delete j;
		delete i;
	}
	
	{	
		std::cout << "\n===Test Wrong Animal===" << std::endl;
		const WrongAnimal *wa = new WrongCat();
		wa->makeSound();
		std::cout << wa->getType() << " " << std::endl;

		delete wa;
	}

	{		
		std::cout << "\n=== Brain tests ===" << std::endl;
		
		Animal*	doggo = new Dog();
	
		static_cast<Dog*>(doggo)->putIdea("I want cake", 0);
		static_cast<Dog*>(doggo)->putIdea("Walk", 1);
		static_cast<Dog*>(doggo)->putIdea("The cat is nice", 2);
		static_cast<Dog*>(doggo)->putIdea("wow", 3);
		static_cast<Dog*>(doggo)->putIdea("Much code", 4);
		std::cout << static_cast<Dog*>(doggo)->getIdea(0) << std::endl;
		std::cout << static_cast<Dog*>(doggo)->getIdea(1) << std::endl;
		std::cout << static_cast<Dog*>(doggo)->getIdea(2) << std::endl;
		std::cout << static_cast<Dog*>(doggo)->getIdea(3) << std::endl;
		std::cout << static_cast<Dog*>(doggo)->getIdea(4) << std::endl;
		
		delete doggo;		
	}
	
	{
		std::cout << "\n=== Dog cpy assignment operator test ===" << std::endl;
		Dog *Abrek = new Dog();

		static_cast<Dog*>(Abrek)->putIdea("Woof", 0);
		static_cast<Dog*>(Abrek)->putIdea("Bark", 1);
		static_cast<Dog*>(Abrek)->putIdea("Park", 2);
		static_cast<Dog*>(Abrek)->putIdea("Walk", 3);

		Dog Max;
		
		Max = *Abrek;
		delete Abrek;
		std::cout << Max.getIdea(0) << std::endl;
		std::cout << Max.getIdea(1) << std::endl;
		std::cout << Max.getIdea(2) << std::endl;
		std::cout << Max.getIdea(3) << std::endl;
	}

		{
		std::cout << "\n=== Cat cpy assignment operator test ===" << std::endl;
		Cat *Bibi = new Cat();

		Bibi->putIdea("Meow", 0);
		Bibi->putIdea("Laser", 1);
		Bibi->putIdea("Bug", 2);
		Bibi->putIdea("Zoom", 3);

		Cat Riji;
		
		Riji = *Bibi;
		delete Bibi;
		std::cout << Riji.getIdea(0) << std::endl;
		std::cout << Riji.getIdea(1) << std::endl;
		std::cout << Riji.getIdea(2) << std::endl;
		std::cout << Riji.getIdea(3) << std::endl;
	}
	
	{
		std::cout << "\n===Dog Cpy Ctor Test===" << std::endl;
		Dog doggo2;
	
		doggo2.putIdea("I want cake", 0);
		doggo2.putIdea("Walk", 1);
		doggo2.putIdea("The cat is nice", 2);
		doggo2.putIdea("wow", 3);
		doggo2.putIdea("Much code", 4);
	
		Dog doggo3(doggo2);
		
	
		std::cout << doggo3.getIdea(0) << std::endl;
		std::cout << doggo3.getIdea(1) << std::endl;
		std::cout << doggo3.getIdea(2) << std::endl;
		std::cout << doggo3.getIdea(3) << std::endl;
		std::cout << doggo3.getIdea(4) << std::endl;		
	}
	
	{
		std::cout << "\n===Animal array test===:" << std::endl;
		Animal	*zoo[4] = {new Dog(), new Dog(), new Cat(), new Cat()};
		zoo[0]->makeSound();
		zoo[1]->makeSound();
		zoo[2]->makeSound();
		zoo[3]->makeSound();
		for (int i = 0; i < 4; i++)
		{
			delete zoo[i];
		}
	}
	return (0);
}
