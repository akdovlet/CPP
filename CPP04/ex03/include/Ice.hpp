/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 17:25:52 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/12 19:28:07 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
private:

public:
	Ice();
	Ice(const Ice& other);
	Ice&	operator=(const Ice& other);
	~Ice();

	Ice*	clone() const;
	void	use(ICharacter& target);
};

#endif
