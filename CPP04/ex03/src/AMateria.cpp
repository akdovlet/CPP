/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:03:31 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/13 13:01:54 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
}

AMateria::AMateria(std::string const& type) : _type(type)
{
}

AMateria::AMateria(const AMateria& other) : _type(other._type)
{
}

AMateria&	AMateria::operator=(const AMateria& other)
{
	(void)other;
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
	(void)target;
}

// void AMateria::use(ICharacter& target)
// {
// 	(void)target;
// }
