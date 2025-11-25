#pragma once
#include"WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	protected:

	public:

		WrongCat();
		WrongCat(const WrongCat& src);
		WrongCat& operator=(const WrongCat &src);
		~WrongCat();

		const std::string& getType() const;
		void makeSound() const;
};
