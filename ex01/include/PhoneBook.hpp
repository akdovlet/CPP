/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:29:42 by akdovlet          #+#    #+#             */
/*   Updated: 2025/06/27 16:07:08 by akdovlet         ###   ########.fr       */
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
	size_t get_index();
	size_t get_count();
	void search(void);
	void increase(void);
private:
	size_t		_index;
	size_t		_count;
	Contact	WhitePages[8];
};

// #include "maclasse.hpp"

// void PhoneBook::mabite(){
// 	std::cout << "hello " << std::endl;
// }
