/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:04:59 by phwang            #+#    #+#             */
/*   Updated: 2025/03/18 21:42:40 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Color.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"

using std::cout;
using std::endl;

int main(void)
{
	try{
		Bureaucrat a("Champignon", 1);
		Bureaucrat b("Michel", 60);
		cout << a;
		cout << b;
		Form one("first form", 40, 40);
		cout << one;
		b.signForm(one);
		a.signForm(one);
		cout << one;
		a.signForm(one);
	}
	catch (std::exception &e)
	{
		cout << RED << "Catch an exception : " << e.what() << RESET << endl;
	}
	
	return 0;
}
