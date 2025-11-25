#pragma once

#include<string>
#include<iostream>

class ClapTrap
{
	private:

	std::string _name;
	int			_hit_points;
	int			_energy_points;
	int			_attack_damage;

	public:

			ClapTrap(std::string n_name);
			ClapTrap(const ClapTrap& src);
			ClapTrap& operator=(const ClapTrap &src);
			~ClapTrap();

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};
