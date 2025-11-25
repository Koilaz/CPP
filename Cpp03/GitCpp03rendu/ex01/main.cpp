#include"ScavTrap.hpp"

int main()
{
	ScavTrap nar("Naruto");
	ScavTrap narc (nar);

	nar.attack("Kabuto");
	nar.beRepaired(2);
	nar.guardGate();
	nar.takeDamage(200);
	nar.guardGate();

	return (0);
}
