#pragma once

#include"ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:

		FragTrap();
		FragTrap(std::string n_name);
		FragTrap(const FragTrap& src);
		FragTrap& operator=(const FragTrap &src);
		virtual ~FragTrap();

		void	attack(const std::string& target);
		void	highFivesGuys();
};
