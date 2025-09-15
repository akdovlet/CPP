/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 01:44:09 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/15 04:33:02 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>

class GradeTooHighException : std::exception
{
	virtual const char* what() const throw();
};

class GradeTooLowException : std::exception
{
	virtual const char* what() const throw();
};

class Bureaucrat
{
private:
	std::string const	_name;
	int					_grade;
public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat(const std::string &name, const int grade);
	Bureaucrat&	operator=(const Bureaucrat& other);
	~Bureaucrat();
	
	const std::string&	getName();
	int					getGrade();
	void				incrementGrade();
	void				decrementGrade();
};

Bureaucrat::Bureaucrat() : _name(""), _grade(150)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
}

Bureaucrat::~Bureaucrat()
{
}

const char* GradeTooHighException::what() const throw()
{
	return ("Error: Grade too high");
}

const char* GradeTooLowException::what() const throw()
{
	return ("Error: Grade too low");
}

#endif
