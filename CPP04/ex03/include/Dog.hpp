/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:05:30 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/10 16:45:10 by akdovlet         ###   ########.fr       */
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
	Dog(const Dog& other);
	Dog&	operator=(const Dog& other);
	~Dog();
	
	void	makeSound() const;

	void				putIdea(const std::string& str, const int index);
	const std::string	getIdea(const int index) const;
};

#endif
