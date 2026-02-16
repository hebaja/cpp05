#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string name, int grade_sign, int grade_exec) : name(name), is_signed(false), grade_sign(grade_sign), grade_exec(grade_exec) {}

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
	return "GradeTooHighException.";
}

const char	*Form::GradeTooLowException::what() const throw() {
	return "GradeTooLowException.";
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
