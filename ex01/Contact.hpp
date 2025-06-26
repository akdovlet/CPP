/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:50:37 by akdovlet          #+#    #+#             */
/*   Updated: 2025/06/26 19:33:13 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class	Contact
{
	public:
		void	get_info(void);
		int		create(void);
	private:
		std::string	_FirstName;
		std::string	_LastName;
		std::string	_Nickname;
		std::string	_PhoneNumber;
		std::string	_Secret;
};
