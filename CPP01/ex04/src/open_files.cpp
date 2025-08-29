/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 23:09:01 by akdovlet          #+#    #+#             */
/*   Updated: 2025/08/29 22:00:18 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "akSed.hpp"

bool	open_files(const char *filename, std::ifstream &infile, std::ofstream &outfile)
{
	std::string		newFileName;

	newFileName = filename;
	newFileName += ".replace";
	infile.open(filename);
	if (infile.fail())
	{
		std::cerr << "Error opening input file: " << filename << std::endl;
		return (false);
	}
	outfile.open(newFileName.c_str());
	if (outfile.fail())
	{
		std::cerr << "Error opening output file: " << filename << ".replace" << std::endl;
		infile.close();
		return (false);
	}
	return (true);
}
