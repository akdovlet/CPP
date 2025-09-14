/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mList.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 20:05:44 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/14 20:54:29 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLIST_HPP
#define MLIST_HPP

#include "AMateria.hpp"

class mList
{
public:
	AMateria	*_materia;
	mList		*_next;
	
	mList();
	mList(AMateria *materia);
	mList(const mList& other);
	mList& operator=(mList other);
	~mList();
	
	void swap(mList& left, mList &right);
};

#endif
