/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 19:20:44 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/12 19:26:15 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

class Cure : public AMateria
{
private:

public:
	Cure();
	Cure(const Cure& other);
	Cure&	operator=(const Cure& other);
	~Cure();

	Cure*	clone() const;
	void	use(ICharacter& target);
};


#endif
