#include"Zombie.hpp"

void Zombie::announce(void)
{
    std::cout << name <<": BraiiiiiiinnnzzzZ..." << std::endl;
}
void Zombie::setName(std::string new_name)
{
    name = new_name;
}
Zombie::Zombie()
{}

Zombie::Zombie(std::string new_name) : name(new_name)
{}

Zombie::~Zombie()
{
    std::cout<<name<<" deconstruit." << std::endl;
}