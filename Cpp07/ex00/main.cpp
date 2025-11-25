#include "template.hpp"
#include <string.h>

int main()
{
	int a = 42;
	int b = 24;
	std::cout<<"before swap a = "<<a<<" b = "<<b<<std::endl;
	swap(a,b);
	std::cout<<"after swap a = "<<a<<" b = "<<b<<std::endl;

	std::string str1 = "1 Salut";
	std::string str2 = "2 Ola";
	std::cout<<"before swap str1 = "<<str1<<" str2 = "<<str2<<std::endl;
	swap(str1,str2);
	std::cout<<"after swap str1 = "<<str1<<" str2 = "<<str2<<std::endl;

	std::cout<<"a = "<<a<<" b = "<<b<<" min = "<<min(a,b)<<" max = "<<max(a,b)<<std::endl;
	std::cout<<"str1 = "<<str1<<" str2 = "<<str2<<" min = \""<<min(str1,str2)<<"\" max = \""<<max(str1,str2)<<"\""<<std::endl;

	std::cout<<std::endl;
	{
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	return 0;
	//swap(a , str1);
}
