/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:49:41 by phwang            #+#    #+#             */
/*   Updated: 2025/03/18 23:28:59 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <fstream>

#define CREATION_FILE_FAIL_EXCEPTION "Couldn't create the file for some reason"


class ShrubberyCreationForm : public AForm
{
private:
	const std::string _target;

public:
	/* constructor default, copy, affecation operator, destructor */
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string formName);
	ShrubberyCreationForm(const ShrubberyCreationForm &toCopy);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &toCopy);
	~ShrubberyCreationForm();
	
	void execute(Bureaucrat const & executor) const;

	class FileCreationException : public std::exception
	{
		public :
			virtual const char *what() const throw();
	};
};

#endif