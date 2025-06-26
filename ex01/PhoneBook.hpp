/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:29:42 by akdovlet          #+#    #+#             */
/*   Updated: 2025/06/26 20:11:01 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"
#include <string>
#include <iostream>

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();
	void add(void);
	void get(std::string){};
	void increase(void);
private:
	int		_index;
	Contact	WhitePages[8];
};

// #include "maclasse.hpp"

// void PhoneBook::mabite(){
// 	std::cout << "hello " << std::endl;
// }
