/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:46:14 by phwang            #+#    #+#             */
/*   Updated: 2025/03/19 01:40:05 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

using std::cout;
using std::endl;

Bureaucrat::Bureaucrat() : _name("Anonymous"), _grade(0)
{
	cout << RED << "Default Bureaucrat constructor called" << RESET << endl;
}


Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	cout << RED << "Bureaucrat Parameter constructor called" << RESET << endl;
	if(grade > 150)
	{
		throw(GradeTooLowException());
	}
	else if(grade < 1)
	{
		throw(GradeTooHighException());
	}
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &toCopy)
{
	cout << RED << "Bureaucrat Copy constructor called" << RESET << endl;
	*this = toCopy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &toCopy)
{
	cout << RED << "Affectation operator Bureaucrat constructor called" << RESET << endl;
	if(this != &toCopy)
	{
		_grade = toCopy._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	cout << RED << "Bureaucrat Destructor called" << RESET << endl;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

std::string Bureaucrat::getName() const
{
	return _name;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &toDisplay)
{
	os << toDisplay.getName() << ", bureaucrate grade " << toDisplay.getGrade() << ".\n";
	return os;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high, has to be maximal 1";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low, has to be minimal 150";
}

void Bureaucrat::incrementGrade()
{
	if(_grade - 1 < 1)
	{
		throw(GradeTooHighException());
	}
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if(_grade + 1 > 150)
	{
		throw(GradeTooLowException());
	}
	_grade++;
}
