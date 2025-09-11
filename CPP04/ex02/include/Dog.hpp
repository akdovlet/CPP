/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:05:30 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/11 19:06:04 by akdovlet         ###   ########.fr       */
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

	void	swap(Dog& lha, Dog& rha);
public:
	Dog();
	Dog(const Dog& cat);
	Dog&	operator=(Dog other);
	~Dog();
	
	void	makeSound() const;

	void				putIdea(const std::string& str, const int index);
	const std::string	getIdea(const int index) const;
};

#endif
