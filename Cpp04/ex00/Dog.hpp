#pragma once
#include"Animal.hpp"

class Dog: public Animal
{
	protected:

	public:

		Dog();
		Dog(const Dog& src);
		Dog& operator=(const Dog &src);
		~Dog();

		const std::string& getType() const;
		void makeSound() const;
};

