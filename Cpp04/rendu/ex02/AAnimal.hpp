#pragma once

#include<string>
#include<iostream>

class AAnimal
{
	protected:

	std::string _type;

	public:

			AAnimal();
			AAnimal(const AAnimal& src);
			AAnimal& operator=(const AAnimal &src);
			virtual ~AAnimal();
			virtual void makeSound() const = 0;
			virtual const std::string& getType() const;
};
