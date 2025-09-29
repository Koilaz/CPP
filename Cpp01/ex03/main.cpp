#include"HumanA.hpp"
#include"HumanB.hpp"
#include"Weapon.hpp"

int main()
{
    {
    Weapon club = Weapon("Crowbar");
    HumanA bob("Gordon", club);
    bob.attack();
    club.setType("Gravity Gun");
    bob.attack();
    }

    {
    Weapon club = Weapon("Wrench");
    HumanB jim("AD");
    jim.attack();
    jim.setWeapon(club);
    jim.attack();
    club.setType("telekinesis plasmid");
    jim.attack();
    }

    return(0);
}