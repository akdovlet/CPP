/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 19:58:51 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/11 20:07:31 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

class ICharacter;

class AMateria
{
private:
	std::string	_type;
public:
	AMateria();
	AMateria(std::string const &type);
	AMateria(const AMateria& other);
	AMateria& operator=(const AMateria& other);
	~AMateria();

	const std::string &getType() const;

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

AMateria::AMateria()
{
}

AMateria::~AMateria()
{
}


#endif
