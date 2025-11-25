#pragma once

#include"ScavTrap.hpp"
#include"FragTrap.hpp"

class DiamondTrap: public FragTrap , public ScavTrap
{
	private:
		std::string _name;

	public:

		DiamondTrap();
		DiamondTrap(std::string n_name);
		DiamondTrap(const DiamondTrap& src);
		DiamondTrap& operator=(const DiamondTrap &src);
		~DiamondTrap();

		void	attack(const std::string& target);
		void	whoAmI();
};
