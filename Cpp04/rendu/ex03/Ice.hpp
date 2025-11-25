#pragma once
#include "AMateria.hpp"

class Ice : public AMateria
{
	protected:

	public:

	Ice(): AMateria("ice") {};
	Ice(const Ice &src);
	Ice& operator=(const Ice &src);
	~Ice() {};

	AMateria* clone() const;
	void use(ICharacter& target);
};
