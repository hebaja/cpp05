#pragma once

#include "AForm.hpp"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern &i);
		Intern &operator=(const Intern &i);
		AForm *makeForm(std::string form_name, std::string target);
		enum Param {
			Shrubbery,
			Robotomy,
			Presidential,
			Unknown,
		};

};
