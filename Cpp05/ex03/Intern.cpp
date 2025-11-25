#include "Intern.hpp"

AForm *Intern::makeForm(std::string form_name, std::string target)
{
	AForm *ret;
	std::string form[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int i;
	for (i = 0; i < 3; i++)
	{
		if (form[i] == form_name)
			break;
	}
	switch (i)
	{
    case 0:
	{
		ret = new ShrubberyCreationForm(target);
		std::cout<<"Intern creates "<< form_name<< std::endl;
	}
		break;
		case 1:
	{
		ret = new RobotomyRequestForm(target);
    	std::cout<<"Intern creates "<< form_name<< std::endl;
	}
		break;
		case 2:
	{
		ret = new PresidentialPardonForm(target);
		std::cout<<"Intern creates "<< form_name<< std::endl;
	}
		break;
	default:
		ret = NULL;
	}
	return (ret);
}

Intern::Intern()
{}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& src)
{
	(void) src;
	return *this;
}

Intern::~Intern()
{

}
