/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:27:41 by phwang            #+#    #+#             */
/*   Updated: 2025/03/19 01:13:44 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Color.hpp"
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