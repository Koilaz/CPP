#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

bool seed = (std::srand(std::time(NULL)), true);

Base * Base::generate(void)
{
	Base *ptr;
	int r = rand() % 3;
	switch (r + 1)
	{
	case 1:
		ptr = new A;
		break;
	case 2:
		ptr = new B;
		break;
	case 3:
		ptr = new C;
		break;
	default:
		ptr = NULL;
		break;
	}
	return ptr;
}
void Base::identify(Base& p)
{
	A a;
	B b;
	C c;
	try
	{
		a = dynamic_cast<A&>(p);
	}
	catch(const std::exception& e)
	{
		std::cout<<"A"<<std::endl;
	}
	try
	{
		b = dynamic_cast<B&>(p);
	}
	catch(const std::exception& e)
	{
		std::cout<<"B"<<std::endl;
	}
	try
	{
		c = dynamic_cast<C&>(p);
	}
	catch(const std::exception& e)
	{
		std::cout<<"C"<<std::endl;
	}
}


void Base::identify(Base* p)
{
	A	*a;
	B	*b;
	C	*c;
	if ((a = dynamic_cast<A*>(p)))
		std::cout<<"A"<<std::endl;
	if ((b = dynamic_cast<B*>(p)))
		std::cout<<"B"<<std::endl;
	if ((c = dynamic_cast<C*>(p)))
		std::cout<<"C"<<std::endl;
}

Base::~Base()
{

}
