/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:23:19 by phwang            #+#    #+#             */
/*   Updated: 2025/03/24 15:06:55 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

#define ALREADY_SIGNED_EXCEPTION "this form is already signed"
#define NOT_SIGNED_EXCEPTION "this form is not signed"
#define GRADE_TOO_LOW_SIGN_EXCEPTION "Bureaucrate grade is too low to sign the form"
#define GRADE_TOO_LOW_EXEC_EXCEPTION "Bureaucrate grade is too low to execute the form"
#define GRADE_FORM_TOO_HIGH_EXCEPTION "Form grade is too high, has to be maximal 1"
#define GRADE_FORM_TOO_LOW_EXCEPTION "Form grade is too low, has to be minimal 150"

#define SIGN_FLAG 1
#define EXEC_FLAG 2

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	bool _isSigned;
	const int _gradeForSign;
	const int _gradeForExec;

public:
	/* constructor default, copy, affecation operator, destructor */
	AForm();
	AForm(std::string name, int gradeSign, int gradeExec);
	AForm(const AForm &toCopy);
	AForm &operator=(const AForm &toCopy);
	virtual ~AForm();

	std::string getName() const;
	bool getIsSigned() const;
	void beSigned(Bureaucrat &guy);
	int getGrade(int flag) const;

	virtual void execute(Bureaucrat const & executor) const = 0;
	
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
	class NotSignedException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class TooLowToSignException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class TooLowToExecException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const AForm &toDisplay);

#endif