#include"Bureaucrat.hpp"
#include"Form.hpp"

int main()
{
	Bureaucrat	*manu = NULL;
	Form		*Reforme_des_retraites = NULL;
	Form		*Order = NULL;

	try
	{
		Reforme_des_retraites = new Form("Reforme des retraites", 199, 1);
	}
	catch(const std::exception& e)
	{
		std::cout<<"Tried to built a wrong Form\n";
		std::cerr <<"catch exception :"<< e.what() << '\n';
	}

	try
	{
		manu = new Bureaucrat("Manu", 112);
		Order = new Form("Order 66", 49, 1);
		manu->signForm(*Order);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		manu->promotion(111);
		manu->signForm(*Order);
	}

	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	delete Reforme_des_retraites;
	delete manu;
	delete Order;
}
