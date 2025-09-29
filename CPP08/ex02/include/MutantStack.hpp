/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:39:12 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/29 19:32:32 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iterator>

template<typename T>
class MutantStack : public std::stack<T>
{
public:
	class iterator : public std::iterator<	std::random_access_iterator_tag,
											std::stack<T>,
											std::stack<T>,
											const std::stack<T>*,
											const std::stack<T>&>
	{
	private:
		std::stack<T>* t_ptr;
	public:
		typedef std::stack<T>* pointer;
		typedef std::stack<T>& reference;
	
		iterator(std::stack<T>* ptr = NULL) : t_ptr(ptr) {}
		iterator(const iterator& other) : t_ptr(other.t_ptr) {}
		~iterator() {}
	
		iterator& operator=(const iterator& other) { t_ptr = other.t_ptr; return (*this); }	
		iterator& operator++() { t_ptr++; return *this; }
		iterator& operator++(int) { T old = *this; ++(*this); return (old); }
		iterator& operator--() { t_ptr--; return *this; }
		iterator& operator--(int) { T old = *this; --(*this); return (old); }
		iterator operator+(const std::ptrdiff_t mov) { pointer oldPtr = t_ptr;}
		bool	operator==(iterator other) const { return t_ptr == other.t_ptr; }
		bool	operator!=(iterator other) const { return t_ptr != other.t_ptr; }
		
		
		// iterator begin() { return (&top() - size()); }
		// iterator end() { return (&top() + 1); };
	};

	MutantStack();
	~MutantStack();
};

template<typename T>
MutantStack<T>::MutantStack(/* args */)
{
}

template<typename T>
MutantStack<T>::~MutantStack()
{
}


#endif
