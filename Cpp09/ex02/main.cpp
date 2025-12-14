#include <vector>
#include <iostream>
#include"PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error\nargument format expected \" ./PmergeMe \"4 8 137 15..\" \"" << std::endl;
		return 0;
	}
	PmergeMe main;
	try
	{
		main.str_to_vec(argv[1]);
		main.print_results();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
