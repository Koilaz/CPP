#pragma once
#include"IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:

	AMateria *_inventory[4];

	public:
	MateriaSource();
	MateriaSource(MateriaSource &src);
	MateriaSource& operator=(MateriaSource &src);

	~MateriaSource();
	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
};
