#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

class Base
{
	public:
	
		static bool seed;

		static void identify(Base& p);
		static void identify(Base* p);
		static Base *generate(void);

    	virtual ~Base();

	private:

};

#endif // BASE_HPP
