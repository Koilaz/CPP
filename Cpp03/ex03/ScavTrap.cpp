#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Noname_clap_name")
{
	std::cout << "ScavTrap " << this->_name << " has been summoned![Constructor]" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
}

ScavTrap::ScavTrap(std::string n_name) : ClapTrap(n_name)
{
	std::cout << "ScavTrap " << this->_name << " has been summoned![Constructor]" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
}
ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src)
{
	std::cout << "ScavTrap " << this->_name << " used multiclonage[Copy Constructor]" << std::endl;
}
ScavTrap& ScavTrap::operator=(const ScavTrap &src)
{
	this->_name = src._name;
	this->_hit_points = src._hit_points;
	this->_energy_points = src._energy_points;
	this->_attack_damage = src._attack_damage;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->_name << " is deconstructed [Desstructor]" << std::endl;

}

void	ScavTrap::attack(const std::string& target)
{
		if (this->_hit_points <= 0)
	{
		std::cout<<"ScavTrap "<<this->_name <<" try to attack but he is already dead"<<std::endl;
		return;
	}
	if (this->_energy_points > 0)
	{
		std::cout<<"ScavTrap "<< this->_name<<" attacks "<<target<<", causing "
		<<this->_attack_damage<<" points of damage !"<<std::endl;
		this->_energy_points--;
		std::cout<<"ScavTrap "<< this->_name<<" has "<<this->_energy_points<<" energy points left"<<std::endl;
	}
	else
	{
	std::cout<<"ScavTrap "<< this->_name<<"try to attack "<<target
	<<"but has not enough energy points"<<std::endl;
	}
}
void ScavTrap::guardGate()
{
	if (this->_hit_points > 0)
		std::cout << "ScavTrap " << this->_name << " is now in GateKeeper Mode" << std::endl;
	else
		std::cout << "ScavTrap " << this->_name << " try to be in Gatekeeper mode but he is already dead" << std::endl;
}
