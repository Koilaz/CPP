#include"ClapTrap.hpp"

int main()
{
	ClapTrap Naruto("Naruto");

	Naruto.attack("Sasuke");
	Naruto.takeDamage(3);
	Naruto.beRepaired(1);
	Naruto.beRepaired(1);
	Naruto.attack("Gaara");
	Naruto.takeDamage(2);
	Naruto.beRepaired(1);
	Naruto.beRepaired(1);
	Naruto.attack("Pain");
	Naruto.takeDamage(2);
	Naruto.beRepaired(1);
	Naruto.beRepaired(1);
	Naruto.attack("Madara");
	Naruto.beRepaired(1);
	Naruto.beRepaired(1);
	Naruto.attack("Kabuto");
	Naruto.takeDamage(18);
	Naruto.takeDamage(2);
	Naruto.beRepaired(1);
	Naruto.attack("Obito");
	return (0);
}
