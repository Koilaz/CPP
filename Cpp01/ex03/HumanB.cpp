#include"HumanB.hpp"

HumanB::HumanB(std::string n_name) : weapon(NULL)
{
    name = n_name;
}

void HumanB::attack()
{
    if(weapon)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << name << " attacks with their his bare hand... it's not very effective." << std::endl;
}

void HumanB::setWeapon(Weapon& n_weapon)
{
    weapon = &n_weapon;
}

