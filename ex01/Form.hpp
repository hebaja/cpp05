#pragma once

#include <ostream>
#include <string>

class Bureaucrat;

class Form
{

	private:
		const std::string	name;
		bool	is_signed;
		const int		grade_sign;
		const int		grade_exec;

	public:
		Form(std::string name, int grade_sign, int grade_exec);
		~Form();
		Form(const Form &f);
		Form &operator=(const Form &f);
		
		std::string	getName() const;
		bool	getIsSigned() const;
		int		getGradeSign() const;
		int		getGradeExec() const;
		void	beSigned(Bureaucrat &b);
		
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

std::ostream	&operator<<(std::ostream &os, Form &f);
