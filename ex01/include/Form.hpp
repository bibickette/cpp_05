/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:23:19 by phwang            #+#    #+#             */
/*   Updated: 2025/03/18 21:37:54 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

#define ALREADY_SIGNED_EXCEPTION "this form is already signed"
#define GRADE_TOO_LOW_SIGN_EXCEPTION "Bureaucrate grade is too low to sign the form"
#define GRADE_FORM_TOO_HIGH_EXCEPTION "Form grade is too high, has to be maximal 1"
#define GRADE_FORM_TOO_LOW_EXCEPTION "Form grade is too high, has to be maximal 1"

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _isSigned;
	const int _gradeForSign;
	const int _gradeForExec;

public:
	/* constructor default, copy, affecation operator, destructor */
	Form();
	Form(std::string name, int gradeSign, int gradeExec);
	Form(const Form &toCopy);
	Form &operator=(const Form &toCopy);
	~Form();

	std::string getName() const;
	bool getIsSigned() const;
	void beSigned(Bureaucrat &guy);

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class AlreadySignedException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class TooLowToSignException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const Form &toDisplay);

#endif