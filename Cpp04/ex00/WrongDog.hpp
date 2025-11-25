#pragma once
#include"WrongAnimal.hpp"

class WrongDog: public WrongAnimal
{
	protected:

	public:

		WrongDog();
		WrongDog(const WrongDog& src);
		WrongDog& operator=(const WrongDog &src);
		~WrongDog();

		const std::string& getType() const;
		void makeSound() const;
};
