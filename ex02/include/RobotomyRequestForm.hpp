/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:49:18 by phwang            #+#    #+#             */
/*   Updated: 2025/03/18 23:04:46 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{
private:
	const std::string _target;

public:
	/* constructor default, copy, affecation operator, destructor */
	RobotomyRequestForm();
	RobotomyRequestForm(std::string formName);
	RobotomyRequestForm(const RobotomyRequestForm &toCopy);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &toCopy);
	~RobotomyRequestForm();

	void execute(Bureaucrat const & executor) const;


};

#endif