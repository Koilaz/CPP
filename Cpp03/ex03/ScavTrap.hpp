#pragma once

#include"ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:

		ScavTrap();
		ScavTrap(std::string n_name);
		ScavTrap(const ScavTrap& src);
		ScavTrap& operator=(const ScavTrap &src);
		~ScavTrap();

		void	attack(const std::string& target);
		void	guardGate();
};
