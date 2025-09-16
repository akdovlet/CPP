/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:25:55 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/16 20:31:43 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation Form", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	_target = other._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (!getSigned())
		throw NotSignedFormException();
	if (executor.getGrade() > getGradeExec())
		throw GradeTooLowException();

	std::ofstream	outfile;
	outfile.open((_target + "_shrubbery").c_str());
	if (outfile.fail())
	{
		std::cerr << "Error: Failed opening outfile" << std::endl;	
		return ;
	}

	outfile	<< "                          ⣠⣄⢀⡴⢤  ⣤⡀                               " << std::endl
			<< "                    ⢀⡀⢠⣿⠛⠙⠟ ⠛⣙⡿⠿⢿⣆⡖⡎⠷⣤                           " << std::endl
			<< "                 ⣀⣀⣸⡻⠗⠚⠆     ⠃    ⠁ ⠘⢻⡆⢀⣀⣄⣴⣄                     " << std::endl
			<< "                ⠰⣧⠙⠂  ⣠⣄⣀⡀    ⣠⣄⡀     ⠙⠹⠝⠋⠁⠛⣹⡆                   " << std::endl
			<< "                ⢻⣉  ⣰⡾⠛⠉⠉⠉   ⠐⢿⣿⠟   ⢀⣴⣴⣄    ⠉⢿⣶⣄⡀                " << std::endl
			<< "           ⢀⡤⣤⣶⣀⣐⣏⠁⠐⠟⠃         ⠉   ⡴⣌⣿⡿⠛      ⠉⢡⣧⡀               " << std::endl
			<< "       ⣖⠞⣿⠶⠒⠓⠈⠘⠁⣉⣉              ⢀⣰⡯⠛⠋⠻⣧⢶⣤      ⢀⣺⡅ ⢀⢀            " << std::endl
			<< "   ⢠⢦⣤⣼⠍       ⢸⣿⣿⠆               ⠁     ⠈⠉⠁    ⢀⡟⠛⠦⡿⠟⣳⣀          " << std::endl
			<< "  ⢸⡋⠁⢠⣶⣶ ⢀⣤⣶⣤⣀⣀⣀⡉⠁      ⡶⡞⣷⣤⢀                 ⢀⣼⣁⣀   ⠠⣟          " << std::endl
			<< " ⢀⡼⠍ ⠙⠿⠟ ⠚⢉⣤⣄⠁⠁     ⡤⣼⡽⠙⠓  ⠛⠋⢳⠦⡄   ⢀           ⣤⣿⡿⣷   ⠘⠻⢗⣆       " << std::endl
			<< "⢰⡞⠃       ⠻⢯⠏      ⠰⠛⠃            ⣼⣿⣷⠄  ⣀⣀⡀  ⣀  ⠛⠞⠋      ⢼⣇      " << std::endl
			<< "⠸⣴⡦             ⢀⣴⣶⡀    ⣄⣤⡀       ⠙⠻⠛ ⣠⣼⣹⠇⠿⠦⡟⠹⠶⡆         ⣶⠚      " << std::endl
			<< "⢀⡷⠄             ⠈⠻⠿⠁⣠⣤⣤⡾⠃⠑⢓⣆⣀⣀      ⢠⡦⡽⢾⣡⡄    ⠚⠻⢦⣀       ⡯⣤⡴⠒⡆   " << std::endl
			<< "⢀⡿⢒                ⣤⠿⠃      ⠁⠉⠉⠉   ⠚⠉⠉           ⠉⠁       ⠈⠁⠚⢷⣄  " << std::endl
			<< "⠘⠒⣻⠄⢀⡀                                      ⢀⡀⢀  ⠠⣄ ⣄⡀ ⡀  ⢷⠤⠿⠉⠁  " << std::endl
			<< "  ⠙⠚⠛⠳⠶⠶⣆⣠⣦⣠⡄⢀⣠ ⢀⣀ ⢀  ⢀ ⢀  ⢠ ⣀ ⠐⣶⢶⣆⣾⣀⣀⡖⠒⢦⣄⣴⠖⠋⠳⠾⠏⠉⠉⠉⠉⠉⠙⠒⠟⠲⠶⠋      " << std::endl
			<< "           ⠈⠉⠉⠉⠉⠉⠘⠛⠛⠓⠚⠛⠒⠚⠓⠛⠉⠛⠋⠉⠉⠁   ⠈⠉⠁                          " << std::endl;
	outfile.close();
}
