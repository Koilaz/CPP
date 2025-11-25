
#pragma once

#include<string>
#include<iostream>

class WrongAnimal
{
	protected:

	std::string _type;

	public:

			WrongAnimal();
			WrongAnimal(const WrongAnimal& src);
			WrongAnimal& operator=(const WrongAnimal &src);
			virtual ~WrongAnimal();
			void makeSound() const;
			virtual const std::string& getType() const;
};

