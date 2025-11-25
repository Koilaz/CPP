#pragma once
#include<string>
#include<iostream>
#include"ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:

	std::string _type;

	public:

	AMateria();
	AMateria(std::string const &type);
	AMateria(AMateria &src);
	AMateria& operator=(const AMateria &src);
	virtual ~AMateria();

	virtual std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};
