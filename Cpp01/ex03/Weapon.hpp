#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon
{
    private:
        std::string type;
        
    public:
        Weapon(std:: string n_type);
        const std::string&  getType();
        void                setType(std::string new_type);
};
#endif