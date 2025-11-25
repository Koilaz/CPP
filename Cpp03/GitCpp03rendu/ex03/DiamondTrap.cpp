	#include "DiamondTrap.hpp"

	DiamondTrap::DiamondTrap(): ClapTrap("Noname_clap_name"), FragTrap(), ScavTrap()
	{
		this->_name = "No Diamond name";
		this->_attack_damage = 30;
		this->_hit_points = 100;
		this->_energy_points = 50;
		std::cout<<"DiamondTrap with no name was summonde[Default Constructor]"<<std::endl;
	}

	DiamondTrap::DiamondTrap(std::string n_name) : ClapTrap(n_name + "_clap_name"), FragTrap(), ScavTrap()
	{
		this->ClapTrap::_name = n_name + "_clap_name";
		this->_name = n_name;
		this->_attack_damage = 30;
		this->_hit_points = 100;
		this->_energy_points = 50;
		std::cout<<"DiamondTrap "<<this->_name<< " was summoned [Default Constructor]"<<std::endl;
	}

	DiamondTrap::DiamondTrap(const DiamondTrap& src) : ClapTrap(src), FragTrap(), ScavTrap()
	{
		std::cout << "DiamondTrap " << this->_name << " used multiclonage[Copy]" << std::endl;
	}

	DiamondTrap& DiamondTrap::operator=(const DiamondTrap &src)
	{
		ClapTrap::operator=(src);
		this->_name = src._name;
		return *this;
	}

	DiamondTrap::~DiamondTrap()
	{
		std::cout << "DiamondTrap " << this->_name << " was vaporised [destructor]" << std::endl;
	}

	void DiamondTrap::whoAmI()
	{
		std::cout << "Who am i ?\nHi i  Am DiamondTrap " << this->_name << " but you can call me "<<this->ClapTrap::_name << std::endl;
	}

	void	DiamondTrap::attack(const std::string& target)
	{
		ScavTrap::attack(target);
	}
