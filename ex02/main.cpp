#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	{
		try {
			Bureaucrat a("Warrel", 135);
			ShrubberyCreationForm f("tree");
			a.signForm(f);
			a.executeForm(f);
		} catch (std::exception &e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	/*
	{
		try {
			Bureaucrat a("Andrew", 88);
			RobotomyRequestForm f("robot");
			a.signForm(f);
			a.executeForm(f);
		} catch (std::exception &e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	*/
	/*
	{
		try {
			Bureaucrat a("Foo", 4);
			PresidentialPardonForm f("Pardon");
			a.signForm(f);
			a.executeForm(f);
		} catch (std::exception &e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	*/
	return (0);
}
