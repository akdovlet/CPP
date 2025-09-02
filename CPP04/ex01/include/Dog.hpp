/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:05:30 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/02 20:26:59 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
class Dog : public Animal
{
private:
	Brain	*_brain;
public:
	Dog();
	Dog(const Dog& cat);
	Dog&	operator=(const Dog& other);
	~Dog();
	
	void	makeSound() const;
};

#endif
