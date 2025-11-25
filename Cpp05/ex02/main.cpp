#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


int main()
{

	//Presidential Pardon test

	Bureaucrat	palpatine("Manu", 50);
	PresidentialPardonForm  Pardon("Nicolas");

	std::cout<< std::endl << Pardon << std::endl << palpatine << std::endl << std::endl;
	try //try to exec unsigned form
	{
		Pardon.execute(palpatine);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try// try to signed with grade too low
	{
		Pardon.beSigned(palpatine);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		palpatine.promotion(50);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		palpatine.promotion(30);
		Pardon.beSigned(palpatine);
		Pardon.execute(palpatine);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout<< std::endl << Pardon << std::endl << palpatine << std::endl << std::endl;
	try
	{
		palpatine.promotion(18);
		Pardon.execute(palpatine);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout<<std::endl<<"*Robotomy test*"<< std::endl << std::endl;

	//Robotomy test

	RobotomyRequestForm robotomy("Gen Z");

	try
	{
		robotomy.execute(palpatine);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		robotomy.beSigned(palpatine);
		for(int i = 0; i < 40; ++i)
			robotomy.execute(palpatine);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout<<std::endl<<"*Shrubbery Test*"<< std::endl << std::endl;

	ShrubberyCreationForm shrub("tree");
	try
	{
		palpatine.executeForm(shrub);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		shrub.beSigned(palpatine);
		palpatine.executeForm(shrub);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
