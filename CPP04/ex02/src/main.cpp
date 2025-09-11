/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:31:05 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/11 19:14:56 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

#include <iostream>

int main()
{
	{
		std::cout << "\n=== Dog cpy assignment operator test ===" << std::endl;
		Dog *Abrek = new Dog();

		Abrek->putIdea("Woof", 0);
		Abrek->putIdea("Bark", 1);
		Abrek->putIdea("Park", 2);
		Abrek->putIdea("Walk", 3);

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
		std::cout << "\n=== Abstraction Test ===" << std::endl;
		
		// Animal Moha; Uncomment to test
		// Animal *Alex = new Animal();
		// Animal *Clement = new Dog();
	
	}
	return (0);
}
