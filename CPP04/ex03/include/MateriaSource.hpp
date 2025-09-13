/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 12:43:20 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/13 19:37:59 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria	*_source[4];
public:
	MateriaSource();
	MateriaSource(const MateriaSource& other);
	~MateriaSource();
	
	MateriaSource&	operator=(MateriaSource other);
	
	void		learnMateria(AMateria*);
	AMateria*	createMateria(std::string const &type);
	inline void	swap(MateriaSource& left, MateriaSource &right);
};

#endif
