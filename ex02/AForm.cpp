#include "AForm.hpp"
#include "Bureaucrat.hpp"

int check_grade(int grade)
{
	if (grade < 1)
		throw AForm::GradeTooHighException();
	else if (grade > 150)
		throw AForm::GradeTooLowException();
	else
		return grade;
}

AForm::AForm(std::string name, int grade_sign, int grade_exec) : 
	name(name), 
	is_signed(false),
	grade_sign(check_grade(grade_sign)),
	grade_exec(check_grade(grade_exec))
{}

AForm::AForm() : name("Default"), is_signed(false), grade_sign(150), grade_exec(150) {}

AForm::~AForm(){}

AForm::AForm(const AForm &f) : name(f.name), is_signed(f.is_signed), grade_sign(f.grade_sign), grade_exec(f.grade_exec){}

AForm &AForm::operator=(const AForm &f)
{
	if (this != &f)
		this->is_signed = f.getIsSigned();
	return (*this);
}

std::string	AForm::getName() const
{
	return (this->name);
}

bool	AForm::getIsSigned() const
{
	return (this->is_signed);
}

int		AForm::getGradeSign() const
{
	return (this->grade_sign);
}

int		AForm::getGradeExec() const
{
	return (this->grade_exec);
}

const char	*AForm::GradeTooHighException::what() const throw() {
	return "AForm::GradeTooHighException.";
}

const char	*AForm::GradeTooLowException::what() const throw() {
	return "AForm::GradeTooLowException.";
}

const char	*AForm::FormNotSignedException::what() const throw() {
	return "AForm::FormNotSignedException.";
}

void	AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= this->getGradeSign())
	{
		this->is_signed = true;
		std::cout << b.getName() << " signed " << this->getName() << std::endl;
	}
	else
	{
		std::cout << b.getName() << " couldn't sign " << this->getName() << " because grade was too low." << std::endl;
		throw AForm::GradeTooLowException();
	}
}

void	AForm::allowExec(Bureaucrat const & executor) const
{
	if (!this->getIsSigned())
	{
		std::cout << executor.getName() << " could not execute " << this->getName() << std::endl;
		throw AForm::FormNotSignedException();
	}
	if (executor.getGrade() > this->getGradeExec())
	{
		std::cout << executor.getName() << " could not execute " << this->getName() << std::endl;
		throw AForm::GradeTooLowException();
	}
}

std::ostream	&operator<<(std::ostream &os, AForm &f)
{
	os << "AForm " << f.getName() << ". Is signed: " << f.getIsSigned() <<
		". Grade to sign: " << f.getGradeSign() << ". Grade to execute: " << f.getGradeExec();
	return (os);
}
