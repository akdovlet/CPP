/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 19:38:06 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/13 19:48:53 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource()
{
	for (int i = 0; i < 4; i++)
		_source[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		if (_source[i])
			delete _source[i];
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < 4; i++)
	{
		if (other._source[i])
			_source[i] = other._source[i]->clone();
		else
			_source[i] = NULL;
	}
}

inline void	MateriaSource::swap(MateriaSource& left, MateriaSource &right)
{
	using std::swap;
	swap(left._source, right._source);
}

MateriaSource&	MateriaSource::operator=(MateriaSource other)
{
	swap(*this, other);
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *other)
{
	for (int i = 0; i < 4; i++)
	{
		if (!_source[i])
		{
			_source[i] = other;
			return ;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_source[i] && _source[i]->getType() == type)
			return (_source[i]->clone());
	}
	return (0);
}
