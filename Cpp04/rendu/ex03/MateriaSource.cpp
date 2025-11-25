#include"MateriaSource.hpp"

MateriaSource::MateriaSource()
{
for(int i = 0; i < 4;++i)
		this->_inventory[i] = NULL;
}
MateriaSource::MateriaSource(MateriaSource &src)
{
	for (int i = 0; i < 4; ++i)
		this->_inventory[i] = NULL;
	for (int i = 0; i < 4; ++i)
	{
		if (src._inventory[i])
			this->_inventory[i] = src._inventory[i]->clone();
	}
}
MateriaSource& MateriaSource::operator=(MateriaSource &src)
{
	if (this == &src)
		return *this;
	for(int i = 0; i < 4;++i)
	{
		delete this->_inventory[i];
		this->_inventory[i] = NULL;
		if(src._inventory[i])
			this->_inventory[i] = src._inventory[i]->clone();
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for(int i = 0; i < 4;++i)
		delete this->_inventory[i];
}

void MateriaSource::learnMateria(AMateria* m)
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
AMateria* MateriaSource::createMateria(std::string const & type)
{
	AMateria *clone;

	for(int i = 0; i < 4; ++i)
	{
		if(this->_inventory[i] && this->_inventory[i]->getType() == type)
		{
			clone = this->_inventory[i]->clone();
			return (clone);
		}
	}
	return (NULL);
}
