/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mList.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 20:51:47 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/14 20:55:19 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mList.hpp"
#include <iostream>

mList::mList() : _materia(NULL), _next(NULL)
{
	#ifdef DEBUG
	std::cout << "mList default constructor called" << std::endl;
	#endif
}

mList::mList(AMateria *materia) : _materia(materia), _next(NULL)
{
	#ifdef DEBUG
	std::cout << "mList parametrized constructor called" << std::endl;
	#endif
}

mList::mList(const mList& other) : _materia(other._materia), _next(other._next)
{
	#ifdef DEBUG
	std::cout << "mList copy constructor called" << std::endl;
	#endif
}

void	mList::swap(mList& left, mList& right)
{
	using std::swap;
	swap(left._materia, right._materia);
	swap(left._next, right._next);
}

mList& mList::operator=(mList other)
{
	#ifdef DEBUG
	std::cout <<"mList copy assignment operator called" << std::endl;
	#endif
	swap(*this, other);
	return (*this);
}

mList::~mList()
{
	#ifdef DEBUG
	std::cout << "mList destructor called" << std::endl;
	#endif
	delete _materia;
}

