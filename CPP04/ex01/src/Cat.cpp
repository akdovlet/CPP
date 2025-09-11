/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:24:50 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/11 18:53:04 by akdovlet         ###   ########.fr       */
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

void	Cat::swap(Cat& lha, Cat& rha)
{
	using std::swap;
	swap(lha._brain, rha._brain);
}

Cat&	Cat::operator=(Cat other)
{
	std::cout << "Cat assignment operator called" << std::endl;
	swap(*this, other);
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

void	Cat::putIdea(const std::string& str, const int index)
{
	_brain->putIdea(str, index);
}

const std::string	Cat::getIdea(const int index) const
{
	return (_brain->getIdea(index));
}
