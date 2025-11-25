#include "Character.hpp"

Character::Character()
{
	this->_name = "No Name";
	for(int i = 0; i < 4;++i)
		this->_inventory[i] = NULL;
	for(int i = 0; i < 100;++i)
		this->_storage[i] = NULL;
}
Character::Character(std::string name) : _name(name)
{
	for(int i = 0; i < 4;++i)
		this->_inventory[i] = NULL;
	for(int i = 0; i < 100;++i)
		this->_storage[i] = NULL;
}

Character::Character(Character &src)
{
	this->_name = src._name;

	for (int i = 0; i < 4; ++i)
		this->_inventory[i] = NULL;
	for (int i = 0; i < 100; ++i)
		this->_storage[i] = NULL;
	for (int i = 0; i < 4; ++i)
	{
		if (src._inventory[i])
			this->_inventory[i] = src._inventory[i]->clone();
	}
}
Character& Character::operator=(Character &src)
{
	if (this == &src)
		return *this;
	this->_name = src._name;
	for(int i = 0; i < 100;++i)
	{
		delete this->_storage[i];
		this->_storage[i] = NULL;
	}
	for(int i = 0; i < 4;++i)
	{
		delete this->_inventory[i];
		this->_inventory[i] = NULL;
		if(src._inventory[i])
			this->_inventory[i] = src._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	return *this;
}

Character::~Character()
{
	for(int i = 0; i < 4;++i)
		delete this->_inventory[i];
	for(int i = 0; i < 100;++i)
		delete this->_storage[i];
}

std::string const & Character::getName() const
{
	return(this->_name);
}

void Character::equip(AMateria* m)
{
	for(int i = 0; i < 4;++i)
	{
		if(this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		return;
	if (!this->_inventory[idx])
		return;
	for (int i = 0; i < 100; ++i)
	{
		if(!this->_storage[i])
		{
			this->_storage[i] = this->_inventory[idx];
			this->_inventory[idx] = NULL;
			return;
		}
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4)
		return;
	if (!this->_inventory[idx])
		return;
	this->_inventory[idx]->use(target);
}

