/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:58:43 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/25 19:19:06 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>

template<typename T>
void increment(T& a)
{
	a++;
}

template<typename T>
T	print(const T& a)
{
	std::cout << a << std::endl;
	return (a);
}

template<typename T, typename F>
void	iter(T *arr, std::size_t size, F func)
{
	for (std::size_t i = 0; i < size; i++)
		func(arr[i]);
}

#endif
