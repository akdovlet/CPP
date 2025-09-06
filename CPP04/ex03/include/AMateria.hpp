/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 20:05:32 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/04 18:25:53 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

class AMateria
{
	protected:
		std::string	_type;
	public:
		AMateria();
		AMateria(const AMateria& other);
		AMateria(std::string const & type);
		AMateria&	operator=(const AMateria& other);
		virtual ~AMateria();
		
		
		std::string const & getType() const;
		
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
