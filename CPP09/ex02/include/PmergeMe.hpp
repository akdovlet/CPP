/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 12:23:27 by akdovlet          #+#    #+#             */
/*   Updated: 2026/03/26 21:24:40 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iterator>
#include <iostream>
#include <algorithm>

extern int comp_count;

template<typename Iterator>
void	merge_insertion_sort(Iterator first, Iterator last);

#endif
