#include "Harl.hpp"

	void Harl::debug(void)
	{
		std::cout<< "Debug\nJe vous ai deja dis que je ne veux pas qu'on me derange quand je passe l'aspirateur dans ma chambre"<< std::endl;
	}

	void Harl::info(void)
	{
		std::cout<< "Info\nPas content ! pas content ! pas content!" <<std::endl;
	}

	void	Harl::warning(void)
	{
		std::cout<< "Warning\nOn est en 1955 les gars, faut se reveiller hein..."<<std::endl;
	}
	void	Harl::error(void)
	{
		std::cout<< "Error\nQu'on apporte le le FLUGGENGECHEIMEN !" <<std::endl;
	}

	void	Harl::complain( std::string level )
	{
		std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
		void (Harl::*fptr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
		for(int i = 0; i < 4; ++i)
		{
			if (levels[i] == level)
			{
				(this->*fptr[i])();
				break;
			}
			else if (i == 3)
				std::cout<< "Unknow entry" <<std::endl;
		}
	}

