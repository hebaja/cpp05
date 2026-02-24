#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target){}

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("Default"){}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form) : AForm("RobotomyRequestForm", 72, 45), target(form.target){}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &form)
{
	if (this != &form)
		this->target = form.target;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	AForm::allowExec(executor);	
	std::cout << "drrrr-drrrr-drrrr-drrrr-drrrr-drrrr" << std::endl;
	std::srand(std::time(0));
	if (std::rand() % 2 == 0)
		std::cout << executor.getName() << " has been successfully robotomized!" << std::endl;
	else
		std::cout << executor.getName() << " could not be robotomized this time. Try again." << std::endl;

}
