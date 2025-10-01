/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomAccessIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:48:02 by akdovlet          #+#    #+#             */
/*   Updated: 2025/10/01 19:49:28 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOMACCESSITERATOR_HPP
#define RANDOMACCESSITERATOR_HPP

template<typename T>
class randomAccessIterator : public std::iterator<	std::random_access_iterator_tag,
										T,
										T,
										const T*,
										const T&>
{
private:
	T* t_ptr;
public:
	typedef T	value_type;
	typedef T*	pointer;
	typedef T&	reference;
	typedef std::ptrdiff_t	difference_type;
	
	randomAccessIterator(pointer ptr = NULL) : t_ptr(ptr) {}
	randomAccessIterator(const randomAccessIterator& other) : t_ptr(other.t_ptr) {}
	~randomAccessIterator() {}

	operator	bool()const { if (t_ptr) {return true;} else { return (false);} }
	
	randomAccessIterator& operator+=(const difference_type& mov) { t_ptr += mov; return (*this); }
	randomAccessIterator& operator-=(const difference_type& mov) { t_ptr -=mov; return (*this); }
	
	randomAccessIterator& operator++() { t_ptr++; return *this; }
	randomAccessIterator& operator--() { t_ptr--; return *this; }
	randomAccessIterator operator++(int) { randomAccessIterator old(*this); ++t_ptr; return (old); }
	randomAccessIterator operator--(int) { randomAccessIterator old(*this); --t_ptr; return (old); }

	randomAccessIterator operator+(const difference_type mov) { pointer oldPtr = t_ptr; t_ptr += mov; randomAccessIterator tmp(*this); t_ptr = oldPtr; return (tmp); }
	randomAccessIterator operator-(const difference_type mov) { pointer oldPtr = t_ptr; t_ptr -= mov; randomAccessIterator tmp(*this); t_ptr = oldPtr; return (tmp); }
	
	difference_type operator-(const randomAccessIterator& other) { return (std::distance(other.getPointer(), getPointer())) ; }
	
	randomAccessIterator& operator=(const randomAccessIterator& other) { t_ptr = other.t_ptr; return (*this); }
	randomAccessIterator& operator=(randomAccessIterator *ptr) { t_ptr = ptr; return (*this); }
	
	bool	operator==(const randomAccessIterator& other) const { return t_ptr == other.getPointer(); }
	bool	operator!=(const randomAccessIterator& other) const { return t_ptr != other.getConstPointer(); }
	
	reference		operator*() { return (*t_ptr); }
	pointer			operator->() { return (t_ptr); }
	
	pointer	getPointer() { return (t_ptr); }
	const pointer getConstPointer() const { return (t_ptr); }
};

template<typename T>
class reverseIterator : public std::iterator<	std::random_access_iterator_tag,
										T,
										T,
										const T*,
										const T&>
{
private:
	T* t_ptr;
public:
	typedef T	value_type;
	typedef T*	pointer;
	typedef T&	reference;
	typedef std::ptrdiff_t	difference_type;
	
	reverseIterator(pointer ptr = NULL) : t_ptr(ptr) {}
	reverseIterator(const reverseIterator& other) : t_ptr(other.t_ptr) {}
	~reverseIterator() {}

	operator	bool()const { if (t_ptr) {return true;} else { return (false);} }
	
	reverseIterator& operator+=(const difference_type& mov) { t_ptr -= mov; return (*this); }
	reverseIterator& operator-=(const difference_type& mov) { t_ptr +=mov; return (*this); }
	
	reverseIterator& operator++() { t_ptr--; return *this; }
	reverseIterator& operator--() { t_ptr++; return *this; }
	reverseIterator operator++(int) { reverseIterator old(*this); --t_ptr; return (old); }
	reverseIterator operator--(int) { reverseIterator old(*this); ++t_ptr; return (old); }

	reverseIterator operator+(const difference_type mov) { pointer oldPtr = t_ptr; t_ptr -= mov; reverseIterator tmp(*this); t_ptr = oldPtr; return (tmp); }
	reverseIterator operator-(const difference_type mov) { pointer oldPtr = t_ptr; t_ptr += mov; reverseIterator tmp(*this); t_ptr = oldPtr; return (tmp); }
	
	difference_type operator-(const reverseIterator& other) { return (std::distance(other.getPointer(), getPointer())) ; }
	
	reverseIterator& operator=(const reverseIterator& other) { t_ptr = other.t_ptr; return (*this); }
	reverseIterator& operator=(reverseIterator *ptr) { t_ptr = ptr; return (*this); }
	
	bool	operator==(const reverseIterator& other) const { return t_ptr == other.getPointer(); }
	bool	operator!=(const reverseIterator& other) const { return t_ptr != other.getConstPointer(); }
	
	reference		operator*() { return (*t_ptr); }
	pointer			operator->() { return (t_ptr); }
	
	pointer			getPointer() { return (t_ptr); }
	const pointer	getConstPointer() const { return (t_ptr); }
};

#endif
