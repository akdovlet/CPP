/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GroupIterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 16:46:16 by akdovlet          #+#    #+#             */
/*   Updated: 2025/11/27 19:16:45 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GROUPITERATOR_HPP
#define GROUPITERATOR_HPP

#include <iterator>

template<class iterator>
void	iter_swap(iterator a, iterator b)
{
	using std::swap;
	swap(*a, *b);
}

template<class iterator>
void	range_swap(iterator first1, iterator last1, iterator first2)
{
	for (; first1 != last1; first1++, first2++)
		iter_swap<iterator, iterator>(first1, first2);
}

template<typename Iterator>
Iterator	next(Iterator it, typename std::iterator_traits<Iterator>::difference_type n)
{
	std::advance(it, n);
	return (it);
}

template<typename Iterator, typename value = int>
class GroupIterator
{
private:
	Iterator 		_it;
	std::size_t		_size;
public:
	typedef std::random_access_iterator_tag								iterator_category;
	typedef Iterator													iterator_type;
	typedef typename std::iterator_traits<Iterator>::difference_type	difference_type;
	typedef typename std::iterator_traits<Iterator>::value_type			value_type;
	typedef typename std::iterator_traits<Iterator>::pointer			pointer;
	typedef typename std::iterator_traits<Iterator>::reference			reference;

	GroupIterator() : _size(0) {}
	GroupIterator(Iterator _it, std::size_t _size = 0) : _it(_it), _size(_size) {}
	~GroupIterator() {}

	void	swap(GroupIterator& a, GroupIterator& b) { using std::swap;	swap(a._it, b._it); swap(a._size, b._size); }

	Iterator	base() const { return (_it); }
	std::size_t	size() const { return (_size); }

	reference	 operator*() const { return (*next(_it, _size -1)); }

	bool	operator==(const GroupIterator& other){ return (base() == other.base()); }
	bool	operator!=(const GroupIterator& other){ return (base() != other.base()); }
	
	GroupIterator& operator=(GroupIterator other) { swap(*this, other); return (*this); }
	GroupIterator& operator++() { _it += _size; return (*this); }
	GroupIterator operator++(int) { GroupIterator tmp(*this); operator++(); return (tmp); }
	GroupIterator& operator--() { _it -= _size; return (*this); }
	GroupIterator operator--(int) { GroupIterator tmp(*this); operator--(); return (tmp); }

	GroupIterator& operator+=(difference_type increment) { _it += _size * increment; return (*this); }
	GroupIterator& operator-=(difference_type increment) { _it -= _size * increment; return (*this); }

	GroupIterator operator+(difference_type mov) { *this += mov; return (*this); }
	GroupIterator operator-(difference_type mov) { *this -= mov; return (*this); }
	difference_type operator-(const GroupIterator& right) { return ((base() - right.base()) / size()); }

	value_type	operator[](std::size_t pos) { return (_it[pos * _size + _size -1]); }
	value_type	operator[](std::size_t pos) const { return (_it[pos * _size + _size -1]); }
};

template<typename iterator>
void	swap_ranges(GroupIterator<iterator> a, GroupIterator<iterator> b) { range_swap<iterator>(a.base(), a.base() + a.size(), b.base()); }

#endif
