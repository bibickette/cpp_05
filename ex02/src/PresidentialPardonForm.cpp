/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:57:56 by phwang            #+#    #+#             */
/*   Updated: 2025/03/19 01:26:28 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

using std::cout;
using std::endl;

PresidentialPardonForm::PresidentialPardonForm() : AForm("NoName", 25, 5), _target("NoTarget")
{
	cout << GREEN << "Default PresidentialPardonForm constructor called" << RESET << endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string formName) : AForm("PresidentialPardonForm", 25, 5),  _target(formName)
{
	cout << GREEN << "PresidentialPardonForm Parameter constructor called" << RESET << endl;

}


PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &toCopy): AForm(toCopy.getName(), 25, 5), _target(toCopy._target)
{
	cout << GREEN << "PresidentialPardonForm Copy constructor called" << RESET << endl;
	*this = toCopy;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &toCopy)
{
	cout << GREEN << "Affectation operator PresidentialPardonForm constructor called" << RESET << endl;
	if(this != &toCopy) {}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	cout << GREEN << "PresidentialPardonForm Destructor called" << RESET << endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if(!this->getIsSigned())
	{
		throw(NotSignedException());
	}
	if(executor.getGrade() > this->getGrade(EXEC_FLAG))
	{
		throw(TooLowToExecException());
	}
	cout << _target << " has been pardoned by Zaphod Beeblebrox ! <3" << endl ;
}

