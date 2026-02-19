#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(){}

Intern::~Intern(){}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	if (this != &other)
		*this = other;
	return (*this);
}

int	paramToCode(std::string param)
{
	std::string params[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	for (int i = 0; i < 3; i++) {
		if (param.compare(params[i]) == 0)
			return (i);
	}
	return (-1);
}

AForm *Intern::makeForm(std::string form_name, std::string target)
{
	int p = paramToCode(form_name);

	switch (p)
	{
		case 0:
			return new ShrubberyCreationForm(target);
		case 1:
			return new RobotomyRequestForm(target);
		case 2:
			return new PresidentialPardonForm(target);
		default:
			std::cout << "Form not found" << std::endl;
	}
	return (NULL);
}
