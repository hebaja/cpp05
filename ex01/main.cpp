#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	try {
		Bureaucrat a("Warrel", 32);
		Form f("Nevermore", 46, 35);
		std::cout << a << " - " << f << std::endl;
		try {
			a.signForm(f);
			std::cout << f << std::endl;
		} catch (std::exception &e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	return (0);
}
