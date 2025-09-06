/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:03:31 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/04 16:26:43 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
}

AMateria::AMateria(std::string const& type) : _type(type)
{
}

AMateria::AMateria(const AMateria& other)
{
}

AMateria&	AMateria::operator=(const AMateria& other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	return (*this);
}

AMateria::~AMateria()
{
}

std::string const &AMateria::getType() const
{
	return (_type);
}


void AMateria::use(ICharacter& target)
{
	
}
