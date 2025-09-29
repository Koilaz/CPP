#include "Zombie.hpp"

int main()
{
    Zombie zombie1("Pierre zombie 1");
    Zombie* zombie2 = newZombie("Albert zombie 2");
    randomChump("Marcel zombie 3");

    zombie1.announce();
    zombie2->announce();

    delete(zombie2);
    return (0);
}