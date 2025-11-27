/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:46:52 by akdovlet          #+#    #+#             */
/*   Updated: 2025/11/27 19:30:06 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>
#include "GroupIterator.hpp"

template<typename Iterator, typename NodeType>
void	merge_insertion_sort_recursion(GroupIterator<Iterator> first, GroupIterator<Iterator> last, std::list<NodeType> lst)
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
	merge_insertion_sort_recursion(GroupIterator<Iterator>(first.base(), 2 * first.size()), GroupIterator<Iterator>(end.base(), 2 * end.size()), lst);
}

template<typename Iterator>
void	merge_insertion_sort(Iterator first, Iterator last)
{
	int size = last - first;
	if (size < 2)
		return ;

	std::list<GroupIterator<Iterator> >	lst(size);
	merge_insertion_sort_recursion<Iterator, GroupIterator<Iterator> >(GroupIterator<Iterator>(first, 1), GroupIterator<Iterator>(last, 1), lst);
	
	lst.push_back(first);
	lst.push_back(next(first));
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
	

	merge_insertion_sort(it, end);
	for (it = vec.begin(); it != end; it++)
		std::cout << "value: " << *it << std::endl;
	
	return (0);
}
