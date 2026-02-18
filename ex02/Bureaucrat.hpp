#pragma once

#include "AForm.hpp"
#include <string>
#include <iostream>

class Bureaucrat
{
	private:
		const std::string name;
		int	grade;

	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &b);
		Bureaucrat &operator=(const Bureaucrat &b);
		~Bureaucrat();
		
		std::string	getName() const;
		int		getGrade() const;
		void	incrementGrade();
		void	decrementGrade();

		void	signForm(AForm &f);
		void	executeForm(AForm const &form);

		class GradeTooHighException : public std::exception
		{
			public:
				const char * what() const throw();
		};
		
		class GradeTooLowException : public std::exception
		{
			public:
				const char * what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);
