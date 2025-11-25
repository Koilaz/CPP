#include "Dog.hpp"
#include "Cat.hpp"
#include"WrongCat.hpp"
#include"WrongDog.hpp"

int main()
{
	const Animal* Pierre = new Animal();
	const Animal* Rex = new Dog();
	const Animal* Missteigne = new Cat();
	std::cout << Rex->getType() << " " << std::endl;
	std::cout << Missteigne->getType() << " " << std::endl;
	Rex->makeSound(); //will output the Dog sound!
	Missteigne->makeSound();
	Pierre->makeSound();
	delete Pierre;
	delete Rex;
	delete Missteigne;

	std::cout<<std::endl;

	const WrongAnimal* WrongPierre = new WrongAnimal();
	const WrongAnimal* WrongRex = new WrongDog();
	const WrongAnimal* WrongMissteigne = new WrongCat();
	std::cout << WrongRex->getType() << " " << std::endl;
	std::cout << WrongMissteigne->getType() << " " << std::endl;
	WrongRex->makeSound(); //will output the Dog sound!
	WrongMissteigne->makeSound();
	WrongPierre->makeSound();
	delete WrongPierre;
	delete WrongRex;
	delete WrongMissteigne;

	WrongDog Crocdur;
	Crocdur.makeSound();
	return 0;
}
