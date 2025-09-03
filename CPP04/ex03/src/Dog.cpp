/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:25:28 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/03 18:53:48 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	_brain = new Brain();
	_type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	_type = "Dog";
	_brain = new Brain();
	*_brain = *other._brain;
}

Dog&	Dog::operator=(const Dog& other)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &other)
	{
		_type = other._type;
		_brain = new Brain();
		_brain = other._brain;
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

void	Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}

void	Dog::putIdea(const std::string& str, const int index)
{
	_brain->putIdea(str, index);
}

const std::string	Dog::getIdea(const int index) const
{
	return (_brain->getIdea(index));
}
