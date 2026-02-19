#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target){}

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("Default") {}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &form) : AForm(form), target(form.target){}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &form)
{
	if (this != &form)
		this->target = form.target;
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	AForm::allowExec(executor);
	std::cout << executor.getName() << " executed " << this->getName() << std::endl;
	std::string	filename = this->target + "_shrubbery";
	std::ofstream	file(filename.c_str());
	file << "        /\\           /\\           /\\           A\n";
	file << "       / ^\\         /  \\         /  \\         AAA\n";
	file << "      /    \\       / *  \\       / @  \\       AAAAA\n";
	file << "     / ^    \\     /    * \\     / @    \\     AAAAAAA\n";
	file << "    /      ^ \\   / *      \\   /     @  \\   AAAAAAAAA\n";
	file << "   /  ^    ^  \\ /     *  * \\ /   @      \\ AAAAAAAAAAA\n";
	file << "  /      ^     \\_*__________/            \\AAAAAAAAAAAA\n";
	file << " / ^         ^  \\    ||    /   @      @   \\AAAAAAAAAAAA\n";
	file << "/________________\\   ||   /________________\\   |\n";
	file << "        ||         ##||##         ||        ___|___\n";
	file << "      __||__                    ##||##\n";
	file.close();
}
