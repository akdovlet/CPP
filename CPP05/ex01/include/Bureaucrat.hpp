/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 01:44:09 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/15 19:57:02 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	std::string const	_name;
	int					_grade;
public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat(const std::string &name, const int grade);
	Bureaucrat&	operator=(Bureaucrat other);
	~Bureaucrat();
	
	void	swap(Bureaucrat& left, Bureaucrat& right);
	
	const std::string&	getName() const;
	int					getGrade() const;
	void				incrementGrade();
	void				decrementGrade();
	
	void	signForm(Form& form);
	
	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};
	
	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& br);

#endif
