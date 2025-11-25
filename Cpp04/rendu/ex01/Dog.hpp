#pragma once
#include"Animal.hpp"
#include"Brain.hpp"

class Dog: public Animal
{
	private:

		Brain *_brain;

	public:

		Dog();
		Dog(const Dog& src);
		Dog& operator=(const Dog &src);
		~Dog();

		const std::string& getType() const;
		void makeSound() const;
};

