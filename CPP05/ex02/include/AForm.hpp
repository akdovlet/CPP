/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 18:52:44 by akdovlet          #+#    #+#             */
/*   Updated: 2025/09/16 18:55:33 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	bool				_signed;
	const int			_gradeSign;
	const int			_gradeExec;
public:
	AForm();
	AForm(const AForm& other);
	AForm(const std::string &name, int gradeSign, int gradeExec);
	AForm&	operator=(const AForm& other);
	virtual ~AForm();
	
	const std::string&	getName() const;
	bool				getSigned() const;
	int					getGradeSign() const;
	int					getGradeExec() const;
	
	void				beSigned(Bureaucrat& br);
	virtual void		execute(Bureaucrat const& executor) const = 0;

	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};
	
	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};
	
	class NotSignedFormException: public std::exception
	{
		virtual const char* what() const throw();
	};
};

std::ostream&	operator<<(std::ostream& os, const AForm& form);

#endif
