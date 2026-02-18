#pragma once

#include <ostream>
#include <string>

class Bureaucrat;

class AForm
{

	private:
		const std::string	name;
		bool	is_signed;
		const int		grade_sign;
		const int		grade_exec;

	public:
		AForm(std::string name, int grade_sign, int grade_exec);
		AForm();
		~AForm();
		AForm(const AForm &f);
		AForm &operator=(const AForm &f);
		
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
		
		class FormNotSignedException : public std::exception
		{
			public:
				const char * what() const throw();
		};

		
		void	allowExec(Bureaucrat const & executor) const;
		virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream	&operator<<(std::ostream &os, AForm &f);
