/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:25:28 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/11 17:26:35 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal(), _brain(new Brain())
{
	std::cout << "Dog default constructor called" << std::endl;
	_type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other), _brain(new Brain(*other._brain))
{
	std::cout << "Dog copy constructor called" << std::endl;
	_type = "Dog";
}

void	Dog::swap(Dog& lha, Dog& rha)
{
	using std::swap;
	swap(lha._brain, rha._brain);
}

Dog&	Dog::operator=(Dog other)
{
	std::cout << "Dog assignment operator called" << std::endl;
	swap(*this, other);
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
