/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:05:12 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/03 20:33:22 by akdovlet         ###   ########.fr       */
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
public:
	virtual ~Animal(){};
	virtual void	makeSound() const = 0;
	const std::string&	getType() const;
private:
	
};

#endif
