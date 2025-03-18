/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 00:00:47 by phwang            #+#    #+#             */
/*   Updated: 2025/03/19 00:36:05 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define FORM_CREATION_EXCEPTION "Intern couldn't create the form because it doesn't exist"

class Intern
{
private:
	AForm *makeShrub(std::string target);
	AForm *makeRobot(std::string target);
	AForm *makePresident(std::string target);

public:
	/* constructor default, copy, affecation operator, destructor */
	Intern();
	Intern(const Intern &toCopy);
	Intern &operator=(const Intern &toCopy);
	~Intern();
	
	AForm *makeForm(std::string formName, std::string formTarget);

	class FormCreationException : public std::exception
	{
		public :
			virtual const char *what() const throw();
	};
};

#endif