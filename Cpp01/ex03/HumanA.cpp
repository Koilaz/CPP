#include"HumanA.hpp"

HumanA::HumanA(std::string n_name, Weapon& n_weapon)
: name(n_name), weapon(n_weapon)
{}

void HumanA::attack()
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}