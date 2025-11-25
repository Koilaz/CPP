#pragma once
#include"AAnimal.hpp"
#include"Brain.hpp"

class Cat: public AAnimal
{
	private:

		Brain *_brain;

	public:

		Cat();
		Cat(const Cat& src);
		Cat& operator=(const Cat &src);
		~Cat();

		const std::string& getType() const;
		void makeSound() const;
		void setIdea(std::string n_idea, int i);
		std::string getIdea(int i);
};
