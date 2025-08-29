/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 23:07:04 by akdovlet          #+#    #+#             */
/*   Updated: 2025/08/29 21:56:27 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "akSed.hpp"

void	search_and_replace(const std::string &toFind, const std::string &replace, std::string &buf)
{
	std::size_t		pos;
	std::string		begin;
	std::string		end;
	
	if (toFind.empty())
		return ;
	pos = buf.find(toFind);
	while (pos != std::string::npos)
	{
		begin = buf.substr(0, pos);
		end = buf.substr(pos + toFind.length());
		buf = begin + replace + end;
		pos = buf.find(toFind, pos + replace.length());
	}
}
