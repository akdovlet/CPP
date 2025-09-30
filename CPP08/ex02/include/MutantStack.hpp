/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:39:12 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/30 18:47:26 by akdovlet         ###   ########.fr       */
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
		typedef std::stack<T>	value_type;
		typedef std::stack<T>*	pointer;
		typedef std::stack<T>&	reference;
		typedef std::ptrdiff_t	difference_type;
		
		iterator(pointer ptr = NULL) : t_ptr(ptr) {}
		iterator(const iterator& other) : t_ptr(other.t_ptr) {}
		~iterator() {}
	
		operator	bool()const { if (t_ptr) {return true;} else { return (false);} }
		
		iterator& operator+=(const difference_type& mov) { t_ptr += mov; return (*this); }
		iterator& operator-=(const difference_type& mov) { t_ptr -=mov; return (*this); }
		
		iterator& operator++() { t_ptr++; return *this; }
		iterator& operator--() { t_ptr--; return *this; }
		iterator operator++(int) { iterator old(*this); ++t_ptr; return (old); }
		iterator operator--(int) { iterator old(*this); --t_ptr; return (old); }
		
		iterator operator+(const difference_type mov) { pointer oldPtr = t_ptr; t_ptr += mov; iterator tmp(*this); t_ptr = oldPtr; return (tmp); }
		iterator operator-(const difference_type mov) { pointer oldPtr = t_ptr; t_ptr -= mov; iterator tmp(*this); t_ptr = oldPtr; return (tmp); }
		
		difference_type operator-(const iterator& other) { return (std::distance(other.getPointer(), getPointer())) ; }
		
		iterator& operator=(const iterator& other) { t_ptr = other.t_ptr; return (*this); }
		iterator& operator=(iterator *ptr) { t_ptr = ptr; return (*this); }	
		
		bool	operator==(const iterator& other) const { return t_ptr == other.getPointer(); }
		bool	operator!=(const iterator& other) const { return t_ptr != other.getConstPointer(); }
		
		reference		operator*() { return (*t_ptr); }
		// const reference operator*() const { return (*t_ptr); }
		pointer			operator->() { return (t_ptr); }
		
		iterator*	getPointer() { return (t_ptr); }
		const iterator* getConstPointer() const { return (t_ptr); }
	};
	
	MutantStack() : st() {}
	MutantStack(const std::stack<T>& other) : std::stack<T>(other) {}
	MutantStack& operator=(const MutantStack& other) { /*stack::operator=(other);*/(void)other; return (*this); }
	~MutantStack() {}
private:
	std::stack<T> st;
};

// template<typename T>
// MutantStack<T>::MutantStack(/* args */)
// {
// }

// template<typename T>
// MutantStack<T>::~MutantStack()
// {
// }


#endif
