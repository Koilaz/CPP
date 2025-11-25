#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Noname")
{
	std::cout << "FragTrap " << this->_name << " has been summoned![Constructor]" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 30;
}

FragTrap::FragTrap(std::string n_name) : ClapTrap(n_name)
{
	std::cout << "FragTrap " << this->_name << " has been summoned![Constructor]" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 30;
}
FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src)
{
	std::cout << "FragTrap " << this->_name << " used multiclonage[Copy Constructor]" << std::endl;
}
FragTrap& FragTrap::operator=(const FragTrap &src)
{
	this->_name = src._name;
	this->_hit_points = src._hit_points;
	this->_energy_points = src._energy_points;
	this->_attack_damage = src._attack_damage;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name << " is deconstructed [Desstructor]" << std::endl;

}

void FragTrap::attack(const std::string& target)
{
		if (this->_hit_points <= 0)
	{
		std::cout<<"FragTrap "<<this->_name <<" try to attack but he is already dead"<<std::endl;
		return;
	}
	if (this->_energy_points > 0)
	{
		std::cout<<"FragTrap "<< this->_name<<" attacks "<<target<<", causing "
		<<this->_attack_damage<<" points of damage !"<<std::endl;
		this->_energy_points--;
		std::cout<<"FragTrap "<< this->_name<<" has "<<this->_energy_points<<" energy points left"<<std::endl;
	}
	else
	{
	std::cout<<"FragTrap "<< this->_name<<"try to attacks "<<target
	<<"but has not enough energy points"<<std::endl;
	}
}
void FragTrap::highFivesGuys()
{
	if (this->_hit_points > 0)
		std::cout << "FragTrap " << this->_name << " requests high fives" << std::endl;
	else
		std::cout << "FragTrap " << this->_name << " try to ask for high fives but he is already dead" << std::endl;
}
