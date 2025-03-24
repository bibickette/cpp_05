/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:49:30 by phwang            #+#    #+#             */
/*   Updated: 2025/03/18 23:04:48 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
private:
	const std::string _target;

public:
	/* constructor default, copy, affecation operator, destructor */
	PresidentialPardonForm();
	PresidentialPardonForm(std::string formName);
	PresidentialPardonForm(const PresidentialPardonForm &toCopy);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &toCopy);
	~PresidentialPardonForm();

	void execute(Bureaucrat const & executor) const;

};

#endif