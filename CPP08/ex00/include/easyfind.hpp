/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 13:49:10 by akdovlet          #+#    #+#             */
/*   Updated: 2025/10/02 16:22:48 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iterator>
#include <algorithm>

template<typename T>
typename T::iterator	easyfind(T& container, int n)
{
	return (std::find(container.begin(), container.end(), n));
};

#endif
