/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 16:05:35 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/26 18:13:29 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template<typename T>
Array<T>::Array() : _size(0)
{
	arr = new T[]();
}

template<typename T>
Array<T>::Array(unsigned int n) : _size(n), arr(new T[n]())
{
}

template<typename T>
Array<T>::Array(const Array& other) : _size(other.size()), arr(new T[_size]())
{
	std::copy(other.arr, other.arr + _size, arr);
}

template<typename T>
void	Array<T>::swap(T& a, T& b)
{
	using std::swap;
	swap(a.arr, b.arr);
	swap(a._size, b._size);
}

template<typename T>
Array<T>& Array<T>::operator=(Array other)
{
	swap(*this, other);
	return (*this);
}

template<typename T>
std::size_t	Array<T>::size() const
{
	return _size;
}

template<typename T>
void	Array<T>::check(size_t i, const std::string &msg) const
{
	if (i >= _size)
		throw std::out_of_range(msg);
}

template<typename T>
T&	Array<T>::operator[](size_t i)
{
	check(i, "subscript out of range");
	return (arr[i]);
}

template<typename T>
Array<T>::~Array()
{
	delete[] arr;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& obj)

{
	os << obj;
	return os;
}

#endif
