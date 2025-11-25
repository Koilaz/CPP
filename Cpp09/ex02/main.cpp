#include "RPN.hpp"
#include <vector>
#include <iostream>

int main(int argc, char **argv)
{
	RPN rpn;
	int result;

	if (argc != 2)
	{
		std::cerr << "Error\nargument format expected \" ./RPN \"1 2 3 + +\" \"" << std::endl;
		return 0;
	}
	try
	{
		rpn.import_input(argv[1]);
		result = rpn.get_result();
		std::cout<<result << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
