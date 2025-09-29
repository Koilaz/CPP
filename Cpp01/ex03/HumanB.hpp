#ifndef HUMANB_HPP
# define HUMANB_HPP

#include"Weapon.hpp"
#include<iostream>

class HumanB
{
    private:

    Weapon*      weapon;
    std::string  name;

    public:

    HumanB(std::string n_name);
    void setWeapon(Weapon& n_weapon);
    void attack();
};
#endif