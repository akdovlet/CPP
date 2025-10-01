/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:39:12 by akdovlet          #+#    #+#             */
/*   Updated: 2025/10/01 19:57:27 by akdovlet         ###   ########.fr       */
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
	typedef	randomAccessIterator<T>			iterator;
	typedef	reverseIterator<T>				reverse_iterator;
	typedef	reverseIterator<const T>		const_reverse_iterator;
	typedef	randomAccessIterator<const T>	const_iterator;

	MutantStack();
	MutantStack(const std::stack<T, Container>& other);
	~MutantStack();
	
	MutantStack& operator=(const MutantStack& other);
	
	iterator	end();
	iterator	begin();

	const_iterator	cend();
	const_iterator	cbegin();

	reverse_iterator rend() { return (reverse_iterator(&std::stack<T, Container>::top() - (std::stack<T, Container>::size() + 1))); }
	reverse_iterator rbegin() { return reverse_iterator(&std::stack<T, Container>::top()); }

	const_reverse_iterator crend() { return (const_reverse_iterator(&std::stack<T, Container>::top() - (std::stack<T, Container>::size() + 1))); }
	const_reverse_iterator crbegin() { return (const_reverse_iterator(&std::stack<T, Container>::top())); }
};

#include "MutantStack.tpp"

#endif
