#include "BitcoinExchange.hpp"
#include <vector>
#include <iostream>

int main(int argc, char **argv)
{
	BitcoinExchange btc;
	if(argc != 2)
	{
		std::cerr<<"Error\nUsage: \"./btc input.txt\""<<std::endl;
		return 0;
	}
	try
	{
		btc.import_data("data.csv");
		btc.output_value(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
