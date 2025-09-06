/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:42:56 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/04 17:13:37 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include <string>

class Cure
{
private:
	std::string _value;
public:
	virtual int	getValue() = 0;
	Cure(/* args */);
	Cure(std::string& value);
	~Cure();
};

Cure::Cure(/* args */)
{
}

Cure::Cure(std::string &value) : _value(value)
{
}

Cure::~Cure()
{
}


#endif
