#pragma once
#include "AMateria.hpp"

class Cure : public AMateria
{
	public:

	Cure(): AMateria("cure") {};
	Cure(const Cure &src);
	Cure& operator=(const Cure &src);
	~Cure() {};

	AMateria* clone() const;
	void use(ICharacter& target);
};
