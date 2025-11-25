	#include "Cure.hpp"

	Cure::Cure(const Cure &src) : AMateria()
	{ this->_type = src.getType(); }

	Cure& Cure::operator=(const Cure &src)
	{
		if (this != &src)
			AMateria::operator=(src);
		return *this;
	}

	AMateria* Cure::clone() const
	{
		AMateria *clone = new Cure;
		return(clone);
	}

	void Cure::use(ICharacter& target)
	{
		std::cout<<"* heals "<< target.getName()<< "'s wounds *"<<std::endl;
	}
