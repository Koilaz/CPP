#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: AForm("Shruberry", 145, 137)
, _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("Shruberry", 145, 137)
, _target("Default target")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
: AForm(other)
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	if (this != &src)
	{
		AForm::operator=(src);
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::string path = this->_target + "_shrubbery";
	std::ofstream os;

	allow_exec(executor);
	os.open(path.c_str(), std::ios::out);
	if (!os)
		throw std::runtime_error("Failed to open file: " + path);
	os<<ASCII_TREE;
	if (!os)
		throw std::runtime_error("Failed to write to file: " + path);
	std::cout<<executor.getName()<< " has succesfully executed shrubbery form, check that nice tree." <<std::endl;
}
