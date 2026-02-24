#include "Form.hpp"
#include "Bureaucrat.hpp"

int check_grade(int grade)
{
	if (grade < 1)
		throw Form::GradeTooHighException();
	else if (grade > 150)
		throw Form::GradeTooLowException();
	else
		return grade;
}

Form::Form(std::string name, int grade_sign, int grade_exec) : 
	name(name), 
	is_signed(false),
	grade_sign(check_grade(grade_sign)),
	grade_exec(check_grade(grade_exec))
{}

Form::Form() : name("Default"), is_signed(false), grade_sign(150), grade_exec(150) {}

Form::~Form(){}

Form::Form(const Form &f) : name(f.name), is_signed(f.is_signed), grade_sign(f.grade_sign), grade_exec(f.grade_exec){}

Form &Form::operator=(const Form &f)
{
	if (this != &f)
		this->is_signed = f.getIsSigned();
	return (*this);
}

std::string	Form::getName() const
{
	return (this->name);
}

bool	Form::getIsSigned() const
{
	return (this->is_signed);
}

int		Form::getGradeSign() const
{
	return (this->grade_sign);
}

int		Form::getGradeExec() const
{
	return (this->grade_exec);
}

const char	*Form::GradeTooHighException::what() const throw() {
	return "Form::GradeTooHighException.";
}

const char	*Form::GradeTooLowException::what() const throw() {
	return "Form::GradeTooLowException.";
}

void	Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= this->getGradeSign())
	{
		this->is_signed = true;
		std::cout << b.getName() << " signed " << this->getName() << std::endl;
	}
	else
	{
		std::cout << b.getName() << " couldn't sign " << this->getName() << " because grade was too low." << std::endl;
		throw Form::GradeTooLowException();
	}
}

std::ostream	&operator<<(std::ostream &os, Form &f)
{
	os << "Form " << f.getName() << ". Is signed: " << f.getIsSigned() <<
		". Grade to sign: " << f.getGradeSign() << ". Grade to execute: " << f.getGradeExec();
	return (os);
}
