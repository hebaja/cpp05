#include "Bureaucrat.hpp"

int	main()
{
	{
		try {
			Bureaucrat a("Raphael", 15);
			std::cout << a << std::endl;
		} catch (std::exception &e) {
			std::cout << "Could not instantiate class. " << e.what() << std::endl;
		}

		try {
			Bureaucrat b("Leonardo", 203);
			std::cout << b << std::endl;
		} catch (std::exception &e) {
			std::cout << "Could not instantiate class. " << e.what() << std::endl;
		}

		try {
			Bureaucrat c("Donatelo", -42);
			std::cout << c << std::endl;
		} catch (std::exception &e) {
			std::cout << "Could not instantiate class. " << e.what() << std::endl;
		}
	}

	/*
	{
		// INCREMENT DECREMENT EXCEPTIONS
		Bureaucrat a("Archimedes", 1);
		Bureaucrat b("Tesla", 150);
		
		std::cout << a << std::endl;
		try {
			a.incrementGrade();
		} catch (std::exception &e) {
			std::cout << "Could not increment grade. " << e.what() << std::endl;
		}

		std::cout << a << std::endl;
		std::cout << b << std::endl;

		try {
			b.decrementGrade();
		} catch (std::exception &e) {
			std::cout << "Could not decrement grade. " << e.what() << std::endl;
		}
		std::cout << b << std::endl;
	}
	*/
	
	// DEFAULT TESTING 
	/*
	{
		Bureaucrat a("John", 121);
		Bureaucrat b("Ronnie", 5);
		Bureaucrat c(a);

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		b = a;
		std::cout << b << std::endl;
		std::cout << c << std::endl;

		a.incrementGrade();
		std::cout << a << std::endl;
		a.decrementGrade();
		std::cout << a << std::endl;
	}
	*/

	return (0);
}
