/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 23:07:04 by akdovlet          #+#    #+#             */
/*   Updated: 2025/07/08 23:07:24 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "akSed.hpp"

size_t	ak_strlen(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
	}
	return (i);
}

void	search_and_replace(const std::string &toFind, const std::string &replace, std::string &buf)
{
	std::size_t		pos;
	std::string		begin;
	std::string		end;
	
	pos = buf.find(toFind);
	while (pos != std::string::npos)
	{
		begin = buf.substr(0, pos);
		end = buf.substr(pos + toFind.length());
		buf = begin + replace + end;
		pos = buf.find(toFind, pos + replace.length());
	}
}
