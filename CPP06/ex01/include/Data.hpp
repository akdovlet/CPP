/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:19:57 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/24 16:59:24 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <string>

class Data
{
private:
	std::string	_value;
public:
	Data();
	Data(const Data& other);
	Data(const std::string& str);
	Data& operator=(const Data& other);
	~Data();

	std::string	getValue();
};

#endif
