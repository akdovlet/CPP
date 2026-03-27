/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 12:23:27 by akdovlet          #+#    #+#             */
/*   Updated: 2026/03/27 11:38:36 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <list>
#include <sstream>

extern int comp_count;

// template<typename Iterator>
// void	merge_insertion_sort(Iterator first, Iterator last);

void	merge_insertion_sort(std::deque<int>::iterator first, std::deque<int>::iterator last);
void	merge_insertion_sort(std::vector<int>::iterator first, std::vector<int>::iterator last);


#endif
