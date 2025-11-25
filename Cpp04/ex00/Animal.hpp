#pragma once

#include<string>
#include<iostream>

class Animal
{
	protected:

	std::string _type;

	public:

			Animal();
			Animal(const Animal& src);
			Animal& operator=(const Animal &src);
			virtual ~Animal();
			virtual void makeSound() const;
			const std::string& getType() const;
};
