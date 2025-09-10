/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 20:14:16 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/10 19:10:44 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
private:
	std::string	_ideas[100];
public:
	Brain();
	Brain(const Brain& other);
	Brain&	operator=(const Brain& other);
	virtual ~Brain();

	void				putIdea(const std::string& str, const int index);
	const std::string	getIdea(const int index) const;
};

#endif
