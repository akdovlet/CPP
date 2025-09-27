/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 13:49:10 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/27 18:34:25 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iterator>

template<typename T>
typename T::iterator	easyfind(T& container, int n)
{
	for (typename T::iterator it = container.begin(); it != container.end(); it++)
		if (*it == n)
			return (it);
	return (container.end());
};

#endif
