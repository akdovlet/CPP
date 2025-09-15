/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 18:52:44 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/15 19:57:54 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool				_signed;
	const int			_gradeSign;
	const int			_gradeExec;
public:
	Form();
	Form(const Form& other);
	Form(const std::string &name, int gradeSign, int gradeExec);
	Form&	operator=(Form other);
	~Form();
	
	void	swap(Form& left, Form& right);
	
	const std::string&	getName() const;
	bool				getSigned() const;
	int					getGradeSign() const;
	int					getGradeExec() const;
	
	void	beSigned(Bureaucrat& br);
	
	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};
	
	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};
};

std::ostream&	operator<<(std::ostream& os, const Form& form);

#endif
