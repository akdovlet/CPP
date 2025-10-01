/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 14:34:48 by akdovlet          #+#    #+#             */
/*   Updated: 2025/10/01 13:39:47 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T> class Array
{
private:
	std::size_t	_size;
	T			*arr;
public:
	Array();
	Array(unsigned int n);
	Array(const Array& other);
	Array&	operator=(Array other);
	T&		operator[](size_t i);
	~Array();
	
	void	swap(T& a, T& b);
	void	check(size_t i, const std::string &msg) const;
	
	std::size_t	size() const;
};

#include "Array.tpp"

#endif
