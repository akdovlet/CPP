/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:46:52 by akdovlet          #+#    #+#             */
/*   Updated: 2026/03/26 15:34:37 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>
#include "GroupIterator.hpp"
#include "PmergeMe.hpp"

template<typename Iterator>
void	merge_insertion_sort_recursion(GroupIterator<Iterator> first, GroupIterator<Iterator> last)
{
	int size = last - first;
	if (size < 2)
		return ;
	
	bool hasStray = size % 2 != 0;
	GroupIterator<Iterator> end = hasStray ? last - 1 : last;
	for (GroupIterator<Iterator> it = first; it != end; it+= 2)
	{
		if (*it > *next(it, 1))
			swap_ranges(it, next(it, 1));
	}
	merge_insertion_sort_recursion(GroupIterator<Iterator>(first.base(), 2 * first.size()), GroupIterator<Iterator>(end.base(), 2 * end.size()));

	typedef std::vector<GroupIterator<Iterator> > t_vgi;
	t_vgi main;
	main.push_back(first);
	main.push_back(first + 1);

	std::vector<typename t_vgi::iterator> pend;
	for (GroupIterator<Iterator> it = first; it != end; it += 2)
	{
		typename t_vgi::iterator tmp = main.insert(end, std::advance(it, 1));
		pend.push_back(tmp);
	}

	if (hasStray)
		pend.push_back(main.end());
	GroupIterator<Iterator> curr = first;
	GroupIterator<Iterator> curr_pend = pend.begin();
	
	for	(typename t_vgi::difference_type pow2 = 1, jn = 0, dist = 2;
		dist <= pend.end() - curr_pend;
		pow2 *= 2, jn = pow2 - jn, dist = 2 * jn)
		{
			typedef GroupIterator<Iterator> gi;
			gi it = curr + dist * 2;
			gi pe = curr_pend + dist;
			while (1)
			{
				--pe;
				typename t_vgi::iterator insertion_point = std::upper_bound(main.begin(), *pe, *it);
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
		typename t_vgi::iterator insertion_point = std::upper_bound(main.begin(), *curr_pend, *curr);
		main.insert(insertion_point, curr);
		++curr_pend;
	}
	
}

template<typename Iterator>
void	merge_insertion_sort(Iterator first, Iterator last)
{
	int size = last - first;
	if (size < 2)
		return ;
	merge_insertion_sort_recursion<Iterator>(GroupIterator<Iterator>(first, 1), GroupIterator<Iterator>(last, 1));
}

int main()
{
	std::vector<int> vec;
	
	vec.push_back(10);
	vec.push_back(2);
	vec.push_back(34);
	vec.push_back(4);
	vec.push_back(22);
	vec.push_back(7);
	vec.push_back(12);
	
	std::vector<int>::iterator it = vec.begin();
	std::vector<int>::iterator end = vec.end();
	

	merge_insertion_sort<typename std::vector<int>::iterator>(it, end);
	for (it = vec.begin(); it != end; it++)
		std::cout << "value: " << *it << std::endl;
	
	return (0);
}
