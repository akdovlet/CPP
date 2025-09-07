/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 23:09:01 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/07 19:43:37 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "akSed.hpp"
#include <sys/stat.h>

bool	dirCheck(const char *filename)
{
	struct stat	s;
	
	if (!stat(filename, &s))
	{
		if (s.st_mode & S_IFDIR)
		{
			std::cerr << "Error: " << filename << " is directory" << std::endl;
			return (false);
		}	
	}
	else
	{
		std::cerr << "Error: " << filename <<": invalid path" << std::endl;
		return (false);		
	}
	return (true);
}

bool	open_files(const char *filename, std::ifstream &infile, std::ofstream &outfile)
{
	std::string		newFileName;

	newFileName = filename;
	newFileName += ".replace";
	if (!dirCheck(filename))
		return (false);
	infile.open(filename);
	if (infile.fail())
	{
		perror("Error: infile");
		return (false);
	}
	outfile.open(newFileName.c_str());
	if (outfile.fail())
	{
		perror("Error: outfile");
		infile.close();
		return (false);
	}
	return (true);
}
