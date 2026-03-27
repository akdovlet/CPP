/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:04:50 by akdovlet          #+#    #+#             */
/*   Updated: 2026/03/27 17:03:05 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GroupIterator.hpp"
#include "PmergeMe.hpp"


template<typename GI>
struct GroupComp
{
	bool operator()(const GI& lhs, const GI& rhs) const
	{
		comp_count++;
		return (*lhs < *rhs);
	}
};

template<typename Iterator>
void	merge_insertion_sort_recursion(GroupIterator<Iterator> first, GroupIterator<Iterator> last)
{
	typedef GroupIterator<Iterator> GI;
	typedef std::list<GI> t_vgi;
	
	int size = last - first;
	if (size < 2)
		return ;
	
	bool hasStray = size % 2 != 0;
	GI end = hasStray ? last - 1 : last;
	for (GI it = first; it != end; it+= 2)
	{
		if (*it > *next(it, 1))
		{
			swap_ranges(it, next(it, 1));
		}
	}
	merge_insertion_sort_recursion<Iterator>(GI(first.base(), 2 * first.size()), GI(end.base(), 2 * end.size()));

	t_vgi main;
	main.push_back(first);
	main.push_back(first + 1);

	std::vector<typename t_vgi::iterator> pend;
	
	for (GI it = first + 2; it != end; it += 2)
	{
		typename t_vgi::iterator tmp = main.insert(main.end(), it + 1);
		pend.push_back(tmp);
	}

	if (hasStray)
		pend.push_back(main.end());
	
	GI curr = first;
	typename std::vector<typename t_vgi::iterator>::iterator curr_pend = pend.begin();
	
	for	(typename t_vgi::difference_type pow2 = 1, jn = 0, dist = 2;
		dist <= pend.end() - curr_pend;
		pow2 *= 2, jn = pow2 - jn, dist = 2 * jn)
		{
			GI it = curr + dist * 2;
			typename std::vector<typename t_vgi::iterator>::iterator pe = curr_pend + dist;
			while (1)
			{
				--pe;
				typename t_vgi::iterator insertion_point = std::upper_bound(main.begin(), *pe, it, GroupComp<GI>());
				main.insert(insertion_point, it);
				if (pe == curr_pend)
					break ;
				it -= 2;
			}
			curr += dist * 2;
			curr_pend += dist;
		}
		
	while (curr_pend != pend.end())
	{
		curr += 2;
		typename t_vgi::iterator insertion_point = std::upper_bound(main.begin(), *curr_pend, curr, GroupComp<GI>());
		main.insert(insertion_point, curr);
		++curr_pend;
	}
	
	std::vector<typename std::iterator_traits<Iterator>::value_type> ordered;
	ordered.reserve(size * first.size());
	for (typename t_vgi::const_iterator it = main.begin(); it != main.end(); it++)
	{
		const GI& group = *it;
		Iterator src = group.base();
		for (std::size_t i = 0; i < group.size(); i++)
		{
			ordered.push_back(*src);
			++src;
		}
	}

	Iterator dest = first.base();
	for (typename std::vector<typename std::iterator_traits<Iterator>::value_type>::const_iterator it = ordered.begin(); it != ordered.end(); ++it)
	{
		*dest = *it;
		++dest;
	}
	
}

void	merge_insertion_sort(std::vector<int>::iterator first, std::vector<int>::iterator last)
{
	int size = last - first;
	if (size < 2)
		return ;
	merge_insertion_sort_recursion(	GroupIterator<std::vector<int>::iterator>(first, 1),
									GroupIterator<std::vector<int>::iterator>(last, 1));
}

void	merge_insertion_sort(std::deque<int>::iterator first, std::deque<int>::iterator last)
{
	int size = last - first;
	if (size < 2)
		return ;
	merge_insertion_sort_recursion(	GroupIterator<std::deque<int>::iterator>(first, 1),
									GroupIterator<std::deque<int>::iterator>(last, 1));
}
