#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"


int main()
{

	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	Bureaucrat stein("Dr Steinman", 1);
	stein.signForm(*rrf);
	stein.executeForm(*rrf);
	delete rrf;
	return 0;
}
