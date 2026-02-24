#include "Bureaucrat.hpp"
#include "Intern.hpp"

int	main()
{
	try {
		Bureaucrat a("Groot", 135);
		Bureaucrat b("Bender", 44);
		Bureaucrat c("Commando", 4);
		Intern intern;
		AForm *f1 = intern.makeForm("shrubbery creation", "little_planet");
		AForm *f2 = intern.makeForm("robotomy request", "futurama");
		AForm *f3 = intern.makeForm("presidential pardon", "captain");
		AForm *f4 = intern.makeForm("unknown", "test");
		(void)f4;
		a.signForm(*f1);
		b.signForm(*f2);
		c.signForm(*f3);
		a.executeForm(*f1);
		b.executeForm(*f2);
		c.executeForm(*f3);
		delete(f1);
		delete(f2);
		delete(f3);
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	return (0);
}
