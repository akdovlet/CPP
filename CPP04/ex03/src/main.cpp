/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:31:05 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/03 19:52:55 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

#include <iostream>

int main()
{
	{
		// No longer allowed, Animal is abstract
		// const Animal* meta = new Animal();
		// const Animal* j = new Dog();
		// const Animal* i = new Cat();
		
		// std::cout << j->getType() << " " << std::endl;
		// std::cout << i->getType() << " " << std::endl;
		// i->makeSound(); //will output the cat sound!
		// j->makeSound();
		// meta->makeSound();
		
		// delete meta;
		// delete j;
		// delete i;
	}
	
	{
		// No longer allowed, Animal is abstract
		// const WrongAnimal *wa = new WrongCat();
		// wa->makeSound();
		// std::cout << wa->getType() << " " << std::endl;

		// delete wa;
	}

	{		
		// No longer allowed, Animal is abstract
		// 
		// std::cout << std::endl;
		// std::cout << "\nBrain tests" << std::endl;
		
		// Animal*	doggo = new Dog();
	
		// std::cout << "\nDoggo ideas:" << std::endl;
		// static_cast<Dog*>(doggo)->putIdea("I want cake", 0);
		// static_cast<Dog*>(doggo)->putIdea("Walk", 1);
		// static_cast<Dog*>(doggo)->putIdea("The cat is nice", 2);
		// static_cast<Dog*>(doggo)->putIdea("wow", 3);
		// static_cast<Dog*>(doggo)->putIdea("Much code", 4);
		// std::cout << static_cast<Dog*>(doggo)->getIdea(0) << std::endl;
		// std::cout << static_cast<Dog*>(doggo)->getIdea(1) << std::endl;
		// std::cout << static_cast<Dog*>(doggo)->getIdea(2) << std::endl;
		// std::cout << static_cast<Dog*>(doggo)->getIdea(3) << std::endl;
		// std::cout << static_cast<Dog*>(doggo)->getIdea(4) << std::endl;
		
		// delete doggo;		
	}
	
	{
		Dog doggo2;
	
		doggo2.putIdea("I want cake", 0);
		doggo2.putIdea("Walk", 1);
		doggo2.putIdea("The cat is nice", 2);
		doggo2.putIdea("wow", 3);
		doggo2.putIdea("Much code", 4);
	
		std::cout << "\nDoggo3 ideas:" << std::endl;
		Dog doggo3 = doggo2;
		
	
		std::cout << doggo3.getIdea(0) << std::endl;
		std::cout << doggo3.getIdea(1) << std::endl;
		std::cout << doggo3.getIdea(2) << std::endl;
		std::cout << doggo3.getIdea(3) << std::endl;
		std::cout << doggo3.getIdea(4) << std::endl;		
	}
	
	// std::cout << "\nAnimal array test:" << std::endl;
	// Animal	zoo[4] = {Dog(), Dog(), Cat(), Cat()};
	return (0);
}
