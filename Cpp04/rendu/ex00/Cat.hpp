#pragma once
#include"Animal.hpp"

class Cat: public Animal
{
	protected:

	public:

		Cat();
		Cat(const Cat& src);
		Cat& operator=(const Cat &src);
		~Cat();

		const std::string& getType() const;
		void makeSound() const;
};
