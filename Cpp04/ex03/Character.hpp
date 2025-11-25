#pragma once

#include"ICharacter.hpp"
#include"AMateria.hpp"

class Character : public ICharacter
{
	private:

	std::string		_name;
	AMateria		*_inventory[4];
	AMateria		*_storage[100];

	public:

	Character();
	Character(std::string name);
	Character(Character &src);
	Character& operator=(Character &src);
	~Character();
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};
