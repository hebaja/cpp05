#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &b) : name(b.name), grade(b.grade){}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &b)
{
	if (this != &b)
		this->grade = b.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(){}

std::string	Bureaucrat::getName() const
{
	return (this->name);
}

int	Bureaucrat::getGrade() const
{
	return (this->grade);
}

void	Bureaucrat::incrementGrade()
{
	int	tmp = this->grade - 1;
	if (tmp < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade = tmp;
}

void	Bureaucrat::decrementGrade()
{
	int	tmp = this->grade + 1;
	if (tmp > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade = tmp;
}

const char	*Bureaucrat::GradeTooHighException::what() const throw() {
	return "GradeTooHighException.";
}

const char	*Bureaucrat::GradeTooLowException::what() const throw() {
	return "GradeTooLowException.";
}

std::ostream &operator<<(std::ostream &os, Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return (os);
}
