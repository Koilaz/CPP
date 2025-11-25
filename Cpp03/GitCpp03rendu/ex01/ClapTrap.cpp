#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string n_name)
: _name(n_name)
, _hit_points(10)
, _energy_points(10)
, _attack_damage(0)
{
	std::cout << "ClapTrap " << this->_name << " has been summoned![Constructor]" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
	*this = src;
	std::cout << "ClapTrap " << this->_name << " has been copied!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &src)
{
	this->_name = src._name;
	this->_hit_points = src._hit_points;
	this->_energy_points = src._energy_points;
	this->_attack_damage = src._attack_damage;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " has been vaporised [Destructor]" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
		if (this->_hit_points <= 0)
	{
		std::cout<<"ClapTrap "<<this->_name <<" try to attack but he is already dead"<<std::endl;
		return;
	}
	if (this->_energy_points > 0)
	{
		std::cout<<"ClapTrap "<< this->_name<<" attacks "<<target<<", causing "
		<<this->_attack_damage<<" points of damage !"<<std::endl;
		this->_energy_points--;
		std::cout<<"ClapTrap "<< this->_name<<" has "<<this->_energy_points<<" energy points left"<<std::endl;
	}
	else
	{
	std::cout<<"ClapTrap "<< this->_name<<"try to attacks "<<target
	<<"but has not enough energy points"<<std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_points <= 0)
	{
		std::cout<<"ClapTrap "<<this->_name <<" is already dead you sick b*stard"<<std::endl;
		return;
	}
	std::cout<<"ClapTrap "<<this->_name <<" was hit and took "<<amount<< " points of damage"<<std::endl;
	this->_hit_points -= amount;
	if (this->_hit_points <= 0)
	{
		this->_hit_points = 0;
		std::cout<<"ClapTrap "<<this->_name<<" died"<<std::endl;
	}
	else
		std::cout<<"ClapTrap "<<this->_name<<"now has "<<this->_hit_points<<" hitpoints left"<<std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
		if (this->_hit_points <= 0)
	{
		std::cout<<"ClapTrap "<<this->_name <<" try to heal but is already dead"<<std::endl;
		return;
	}
	if(this->_energy_points > 0 && this->_hit_points > 0)
	{
	this->_energy_points--;
	this->_hit_points++;
	std::cout<<"ClapTrap "<<this->_name <<" healed of "<<amount<< " hitpoints"<<std::endl;
	std::cout<<"ClapTrap "<< this->_name<<" now has "<<this->_energy_points
	<<" energy points left and "<<this->_hit_points<<" hitpoints"<<std::endl;
	}
	else
		std::cout<<"ClapTrap "<< this->_name<<" try to healbut has not enough energy points"<<std::endl;
}
