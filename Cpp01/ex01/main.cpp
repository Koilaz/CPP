#include "Zombie.hpp"

int main()
{
    int horde_size = 7;
    Zombie *horde = zombieHorde(horde_size, "Pierre");

    for(int i = 0; i < horde_size; ++i)
    {
        horde[i].announce();
    }
    delete[] horde;
    return (0);
}