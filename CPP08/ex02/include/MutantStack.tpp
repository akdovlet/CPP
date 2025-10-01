/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:14:34 by akdovlet          #+#    #+#             */
/*   Updated: 2025/10/01 19:58:02 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack() : std::stack<T, Container>()
{
}

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack(const std::stack<T, Container>& other) : std::stack<T, Container>(other)
{
}

template<typename T, typename Container>
MutantStack<T, Container>::~MutantStack()
{
}

template<typename T, typename Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack& other)
{
	std::stack<T, Container>::operator=(other);
	return (*this); 
}

template<typename T, typename Container>
randomAccessIterator<T>	MutantStack<T, Container>::end() 
{
	return (&std::stack<T, Container>::top() + 1);
}

template<typename T, typename Container>
randomAccessIterator<T>	MutantStack<T, Container>::begin()
{
	return((&std::stack<T, Container>::top() + 1) - std::stack<T, Container>::size());
}

template<typename T, typename Container>
randomAccessIterator<const T>	MutantStack<T, Container>::cend()
{
	return ((&std::stack<T, Container>::top() + 1));
}

template<typename T, typename Container>
randomAccessIterator<const T>	MutantStack<T, Container>::cbegin()
{
	return((&std::stack<T, Container>::top() + 1) - std::stack<T, Container>::size());
}

