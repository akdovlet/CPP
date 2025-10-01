/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:39:12 by akdovlet          #+#    #+#             */
/*   Updated: 2025/10/01 18:46:59 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iterator>
#include "randomAccessIterator.hpp"

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
	typedef	randomAccessIterator<T>	iterator;
	
	MutantStack();
	MutantStack(const std::stack<T, Container>& other);
	~MutantStack();
	
	MutantStack& operator=(const MutantStack& other);
	
	iterator	end();
	iterator	begin();
};

#include "MutantStack.tpp"

#endif
