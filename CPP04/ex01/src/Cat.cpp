/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:24:50 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/10 17:28:11 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal(), _brain(new Brain())
{
	std::cout << "Cat default constructor called" << std::endl;
	_type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other), _brain(new Brain(*other._brain))
{
	std::cout << "Cat copy constructor called" << std::endl;
	_type = "Cat";
}

Cat&	Cat::operator=(const Cat& other)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &other)
	{
		_type = other._type;
		_brain = new Brain();
		_brain = other._brain;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
}

void	Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}
