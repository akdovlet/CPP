/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 19:48:24 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/14 21:39:53 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Floor.hpp"
#include <iostream>

Floor::Floor() : _head(NULL)
{
}

Floor::Floor(const Floor& other) : _head(other._head)
{
}

void	Floor::swap(Floor& left, Floor&right)
{
	using std::swap;
	swap(left._head, right._head);
}

Floor& Floor::operator=(Floor other)
{
	swap(*this, other);
	return (*this);
}

Floor::~Floor()
{
	while (_head)
	{
		mList *tmp = _head->_next;
		delete _head;
		_head = tmp;
	}
}

void	Floor::insertAtBeginning(mList **head, AMateria* materia)
{
	#ifdef DEBUG
	std::cout << "mlist " << __PRETTY_FUNCTION__ << " called" << std::endl;
	#endif
	mList* newNode = new mList();
	newNode->_materia = materia;
	newNode->_next = *head;
	*head = newNode;
}

AMateria*	Floor::pickUpItem(const std::string type)
{
	while (_head)
	{
		if (type == _head->_materia->getType())
		{
			AMateria	*tmp = _head->_materia->clone();
			mList		*newHead = _head->_next;
			delete _head;
			_head = newHead;
			return (tmp);
		}
		_head = _head->_next;
	}
	return (NULL);
}
