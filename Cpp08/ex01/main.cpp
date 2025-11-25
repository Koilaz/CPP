#include "Span.hpp"
#include <vector>
#include <iostream>
#include <ctime>


int main()
{
	srand(time(NULL));

	std::cout<<std::endl<<"*** Test very big span over 10 000 ***\n"<<std::endl;

	Span Big_span(420000);
	try
	{
		for(int i =0; i < 42000; ++i)
		{
			int n = rand();
			Big_span.addNumber(n);
		}
		std::cout<<"Shortest span = "<<Big_span.shortestSpan();
		std::cout<<"\nLongest span = "<<Big_span.longestSpan()<<std::endl;
	}

	catch(const std::exception& e)
	{
		std::cerr <<"catch 3: "<< e.what() << '\n';
	}

	std::cout<<std::endl<<"*** Test for normal Span ***\n"<<std::endl;

	Span span(20);
	try
	{

		for(int i =0; i <= 10; ++i)
		{
			int n = rand() % 100;
			span.addNumber(n);
			std::cout<<n<<" ";
		}
		std::cout<<std::endl;
		std::cout<<"Shortest span = "<<span.shortestSpan();
		std::cout<<"\nLongest span = "<<span.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() <<'\n';
	}

	std::cout<<std::endl<<"\n*** Test add multiple number ***\n"<<std::endl;

	Span add_mul(100);
	std::vector<int> vector;
	for(int i =0; i < 100;++i)
		vector.push_back(5 * i);
	std::vector<int>::iterator start = vector.begin() + 5;
	std::vector<int>::iterator finish = vector.end() - 5;

	{}
	try
	{
		add_mul.addMultipleNumber(start, finish);
		std::cout<<"Shortest span = "<<add_mul.shortestSpan();
		std::cout<<"\nLongest span = "<<add_mul.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout<<std::endl<<"\n*** Test for overfilling Span ***\n"<<std::endl;

	Span too_small(2);
	try
	{
		for(int i =0; i <= 10; ++i)
		{
			int n = rand();
			too_small.addNumber(n);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr <<"catch 2: "<< e.what() << '\n';
	}

	std::cout<<std::endl<<"*** Test from subject ***"<<std::endl;

	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr <<"catch 3: "<< e.what() << '\n';
	}

	return 0;
}
