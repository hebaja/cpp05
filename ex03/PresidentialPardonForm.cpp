#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target){}

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("Default"){}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &form) : AForm("PresidentialPardonForm", 25, 5), target(form.target){}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &form)
{
	if (this != &form)
		this->target = form.target;
	return (*this);
}
	
void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	AForm::allowExec(executor);
	std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
