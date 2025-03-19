/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:31:00 by phwang            #+#    #+#             */
/*   Updated: 2025/03/19 01:40:41 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

using std::cout;
using std::endl;

AForm::AForm() : _name("Anonymous"), _isSigned(false), _gradeForSign(0), _gradeForExec(0)
{
	cout << YELLOW << "Default AForm constructor called" << RESET << endl;
}
AForm::AForm(std::string name, int gradeSign, int gradeExec) : _name(name), _isSigned(false), _gradeForSign(gradeSign), _gradeForExec(gradeExec)
{
	cout << YELLOW << "AForm Parameter constructor called" << RESET << endl;
	if(gradeSign < 1 || gradeExec < 1)
	{
		throw(AForm::GradeTooHighException());
	}
	else if(gradeSign > 150 || gradeExec > 150)
	{
		throw(AForm::GradeTooLowException());		
	}
}

AForm::AForm(const AForm &toCopy) : _name(toCopy._name), _isSigned(toCopy._isSigned), _gradeForSign(toCopy._gradeForSign), _gradeForExec(toCopy._gradeForExec)
{
	cout << YELLOW << "AForm Copy constructor called" << RESET << endl;
	*this = toCopy;
}

AForm &AForm::operator=(const AForm &toCopy)
{
	cout << YELLOW << "Affectation AForm constructor called" << RESET << endl;
	if(this != &toCopy)
	{
		_isSigned = toCopy._isSigned;
	}
	return *this;
}

AForm::~AForm()
{
	cout << YELLOW << "AForm Destructor called" << RESET << endl;
}

std::string AForm::getName() const
{
	return _name;	
}

bool AForm::getIsSigned() const
{
	return _isSigned;
}

void AForm::beSigned(Bureaucrat &guy)
{
	if(guy.getGrade() <= _gradeForSign && _isSigned)
	{
		throw(AlreadySignedException());
		
	}
	else if (guy.getGrade() > _gradeForSign)
	{
		throw(TooLowToSignException());
	}
	_isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return GRADE_FORM_TOO_HIGH_EXCEPTION;
}
const char *AForm::GradeTooLowException::what() const throw()
{
	return GRADE_FORM_TOO_LOW_EXCEPTION;
}
const char *AForm::AlreadySignedException::what() const throw()
{
	return ALREADY_SIGNED_EXCEPTION;
}

const char *AForm::NotSignedException::what() const throw()
{
	return NOT_SIGNED_EXCEPTION;
}

const char *AForm::TooLowToSignException::what() const throw()
{
	return GRADE_TOO_LOW_SIGN_EXCEPTION;
}

const char *AForm::TooLowToExecException::what() const throw()
{
	return GRADE_TOO_LOW_EXEC_EXCEPTION;
}

std::ostream &operator<<(std::ostream &os, const AForm &toDisplay)
{
	os << toDisplay.getName() << " is a" ;
	if(toDisplay.getIsSigned())
	{
		os << " signed form" << endl;
	}
	else
	{
		os << "n unsigned form" << endl;
	}
	return os;
}

int AForm::getGrade(int flag) const
{
	if(flag == SIGN_FLAG)
	{	return _gradeForSign;}
	else if (flag == EXEC_FLAG)
	{	return _gradeForExec;}
	return 0;
}
