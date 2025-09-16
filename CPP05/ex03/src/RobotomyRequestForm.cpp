/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:33:52 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/16 20:39:48 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	_target = other._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (!getSigned())
		throw NotSignedFormException();
	if (executor.getGrade() > getGradeExec())
		throw GradeTooLowException();
	
	std::cout << "\a* drilling noises \a*" << std::endl;

	srand(time(NULL));
	bool	coinFlip = (rand() % 2) != 0;

	if (coinFlip)
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Failed to robotomize " << _target << '.' << std::endl;
}
