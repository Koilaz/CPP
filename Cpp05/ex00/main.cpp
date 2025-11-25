#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat *igor;

	try
	{
		Bureaucrat boris("boris", -1);
	}
	catch(const std::exception& e)
	{
		std::cerr << "exception 1 caught: " << e.what() << std::endl;
	}
	try
	{
		igor = new Bureaucrat("igor", 42);
	}
	catch(const std::exception& e)
	{
		std::cerr << "exception 2 caught: " << e.what() << std::endl;
	}

	std::cout << *igor << std::endl;

	try
	{
		igor->promotion(10);
	}
	catch(const std::exception& e)
	{
		std::cerr << "exception 3 caught: " << e.what() << std::endl;
	}

	std::cout << *igor << std::endl;

	try
	{
		igor->demotion(140);
	}
	catch(const std::exception& e)
	{
		std::cerr << "exception 4 caught: " << e.what() << std::endl;
	}
	std::cout << *igor << std::endl;

	delete igor;
}
