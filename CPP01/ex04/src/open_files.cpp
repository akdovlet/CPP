/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 23:09:01 by akdovlet          #+#    #+#             */
/*   Updated: 2025/07/08 23:09:07 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "akSed.hpp"

bool	open_files(char **av, std::ifstream &infile, std::ofstream &outfile)
{
	std::string		newFileName;

	newFileName = av[1];
	newFileName += ".replace";
	infile.open(av[1]);
	if (infile.fail())
	{
		std::perror("Error: infile");
		return (false);
	}
	outfile.open(newFileName.c_str());
	if (outfile.fail())
	{
		std::perror("Error: outfile");
		infile.close();
		return (false);
	}
	return (true);
}
