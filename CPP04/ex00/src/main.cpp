/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:31:05 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/10 16:13:11 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

#include <iostream>

int main()
{
	std::cout << "Constructors:" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << "\ngetType and makeSound:" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	j->makeSound();
	i->makeSound(); //will output the cat sound!
	meta->makeSound();
	
	std::cout << "\nDestructors" << std::endl;
	delete meta;
	delete j;
	delete i;
	
	std::cout << "\nWrong animal test" << std::endl;
	
	const WrongAnimal *wa = new WrongCat();
	wa->makeSound();
	std::cout << wa->getType() << " " << std::endl;

	const Animal(Cat());
	delete wa;
	
	return (0);
}

