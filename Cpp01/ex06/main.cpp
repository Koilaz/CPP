#include "Harl.hpp"
#include<iostream>
#include<string>

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: wrong number of arguments" << std::endl;
		return (1);
	}
	Harl harl;
	std::string level[4] = {"WARNING", "DEBUG", "INFO", "ERROR"};
	int i;
	for(i = 0; i<=4; i++)
	{
		if(level[i] == argv[1])
		break;
	}
	switch(i)
	{
    case 0:
		harl.complain(level[0]);
    case 1:
		harl.complain(level[1]);
    case 2:
		harl.complain(level[2]);
    case 3:
		harl.complain(level[3]);
		break;
	default:
		std::cout<< "[ Probably complaining about insignificant problems ]"<<std::endl;
	}
}
