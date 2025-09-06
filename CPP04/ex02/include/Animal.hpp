/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:05:12 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/04 15:01:45 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
protected:
	std::string	_type;
	Animal();
	Animal(const Animal& animal);
	virtual Animal&	operator=(const Animal& other);
	virtual				~Animal();
public:
	virtual void		makeSound() const = 0;
	const std::string&	getType() const;
};

#endif
