/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:57:49 by phwang            #+#    #+#             */
/*   Updated: 2025/03/19 01:26:51 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

using std::cout;
using std::endl;

RobotomyRequestForm::RobotomyRequestForm() : AForm("NoName", 25, 5), _target("NoTarget")
{
	cout << GREEN << "Default RobotomyRequestForm constructor called" << RESET << endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string formName) : AForm("RobotomyRequestForm", 25, 5),  _target(formName)
{
	cout << GREEN << "RobotomyRequestForm Parameter constructor called" << RESET << endl;

}


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &toCopy): AForm(toCopy.getName(), 25, 5), _target(toCopy._target)
{
	cout << GREEN << "RobotomyRequestForm Copy constructor called" << RESET << endl;
	*this = toCopy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &toCopy)
{
	cout << GREEN << "Affectation operator RobotomyRequestForm constructor called" << RESET << endl;
	if(this != &toCopy)
	{

	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	cout << GREEN << "RobotomyRequestForm Destructor called" << RESET << endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	static int operation = 0;

	if(!this->getIsSigned())
	{
		throw(NotSignedException());
	}
	if(executor.getGrade() > this->getGrade(EXEC_FLAG))
	{
		throw(TooLowToExecException());
	}
	cout << "* drilling noises *" << endl;
	if(operation % 2 == 0)
	{
		cout << _target << " has been robotomized successfully zzzzz" << endl;
	}
	else
	{
		cout << "Lobotomy has failed" << endl;
	}
	operation++;
}
