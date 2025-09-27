/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:58:43 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/27 13:33:07 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
void increment(T& a)
{
	a++;
	std::cout << a << std::endl;
}

template<typename T>
T	print(const T& a)
{
	std::cout << a << std::endl;
	return (a);
}

template<typename T, typename F>
void	iter(T arr[], std::size_t size, F func)
{
	if (!arr)
		return ;
	for (std::size_t i = 0; i < size; i++)
		func(arr[i]);
}

#endif
