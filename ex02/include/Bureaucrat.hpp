/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:27:41 by phwang            #+#    #+#             */
/*   Updated: 2025/03/19 01:06:37 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Color.hpp"
#include "AForm.hpp"

#define GRADE_TOO_LOW_EXCEPTION "Bureaucrat grade is too low, has to be minimal 150"
#define GRADE_TOO_HIGH_EXCEPTION "Bureaucrat grade is too high, has to be maximal 1"

class AForm;

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;	

public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &toCopy);
	Bureaucrat &operator=(const Bureaucrat &toCopy);
	~Bureaucrat();

	int getGrade() const;
	std::string getName() const;

	void incrementGrade();
	void decrementGrade();
	
	void signForm(AForm &form);
	void executeForm(AForm const & form);

	class GradeTooHighException : public std::exception
	{
		public :
			virtual const char *what() const throw();
			// virtual est utile car on va faire plusieurs excpeiotn
			// si une seule alors osef
	};
	
	class GradeTooLowException : public std::exception
	{
		public :
			virtual const char *what() const throw();
	};

};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &toDisplay);

#endif