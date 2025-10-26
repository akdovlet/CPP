/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GroupIterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 16:46:16 by akdovlet          #+#    #+#             */
/*   Updated: 2025/10/26 17:27:56 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GROUPITERATOR_HPP
#define GROUPITERATOR_HPP

#include <iterator>

template<typename iterator>
class GroupIterator : public std::iterator<
										std::random_access_iterator_tag,
										iterator,
										std::ptrdiff_t,
										iterator*,
										iterator&
										>
{
private:
	iterator 		it;
	std::size_t		size;
public:
	typedef std::random_access_iterator_tag								iterator_category;
	typedef iterator													iterator_type;
	typedef typename std::iterator_traits<iterator>::difference_type	iterator_difference;
	typedef typename std::iterator_traits<iterator>::pointer			iterator_pointer;
	typedef typename std::iterator_traits<iterator>::reference			iterator_reference;
	
	GroupIterator() : size(0) {}
	GroupIterator(iterator it, std::size_t size = 0) : it(it), size(size) {}
	~GroupIterator() {}
	
	void	swap(GroupIterator& a, GroupIterator& b)
	{
		using std::swap;
		swap(a.it, b.it);
		swap(a.size, b.size);
	}
	
	GroupIterator& operator=(GroupIterator other) { swap(*this, other); return (*this); }

	iterator	getIt() { return (it); }
	std::size_t	getSize() { return (size); }
	
};

#endif
