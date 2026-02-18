#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string target;

	public:
		RobotomyRequestForm(std::string target);

		RobotomyRequestForm();
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &f);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &f);

		void execute(Bureaucrat const &executor) const;
};
