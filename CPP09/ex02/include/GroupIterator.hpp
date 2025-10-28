/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GroupIterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 16:46:16 by akdovlet          #+#    #+#             */
/*   Updated: 2025/10/28 18:44:25 by akdovlet         ###   ########.fr       */
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

template<typename iterator, typename value = int>
class GroupIterator
{
private:
	iterator 		it;
	std::size_t		size;
public:
	typedef std::random_access_iterator_tag								iterator_category;
	typedef iterator													iterator_type;
	typedef typename std::iterator_traits<iterator>::difference_type	iterator_difference;
	typedef typename std::iterator_traits<iterator>::value_type			value_type;
	typedef typename std::iterator_traits<iterator>::pointer			iterator_pointer;
	typedef typename std::iterator_traits<iterator>::reference			iterator_reference;

	GroupIterator() : size(0) {}
	GroupIterator(iterator it, std::size_t size = 0) : it(it), size(size) {}
	~GroupIterator() {}

	void	swap(GroupIterator& a, GroupIterator& b) { using std::swap;	swap(a.it, b.it); swap(a.size, b.size); }

	iterator	getIterator() { return (it); }
	std::size_t	getSize() { return (size); }

	value operator*() const { return (it[size - 1]); }

	GroupIterator& operator=(GroupIterator other) { swap(*this, other); return (*this); }
	GroupIterator& operator++() { it += size; return (*this); }
	GroupIterator operator++(int) { GroupIterator tmp(*this); operator++(); return (tmp); }
	GroupIterator& operator--() { it -= size; return (*this); }
	GroupIterator operator--(int) { GroupIterator tmp(*this); operator--(); return (tmp); }

	GroupIterator& operator+=(iterator_difference increment) { it += size * increment; return (*this); }
	GroupIterator& operator-=(iterator_difference increment) { it -= size * increment; return (*this); }

	GroupIterator operator+(iterator_difference mov) { iterator oldIt = it; it += mov; GroupIterator tmp(*this); it = oldIt; return (tmp); }
	GroupIterator operator-(iterator_difference mov) { iterator oldIt = it; it -= mov; GroupIterator tmp(*this); it = oldIt; return (tmp); }
	
	value	operator[](std::size_t pos) { return (it[pos * size + size -1]); }
	value	operator[](std::size_t pos) const { return (it[pos * size + size -1]); }
	
};

template<typename iterator>
void	swap_ranges(GroupIterator<iterator> a, GroupIterator<iterator> b) { range_swap<iterator>(a.getIterator(), a.getIterator() + a.getSize(), b.getIterator()); }

#endif
