#include "Dog.hpp"
#include "Cat.hpp"


int main()
{

	//AAnimal Platypus;

	const int array_size = 6;

	AAnimal *spa[array_size];

	for (int i = 0; i < array_size; ++i)
	{
		if (i < array_size / 2)
			spa[i] = new Dog();
		else
			spa[i] = new Cat();
	}
	for (int i = 0; i < array_size; ++i)
		delete spa[i];

	std::cout<<std::endl;

	Cat Ronron;
	Ronron.setIdea("Go inside", 0);
	Ronron.setIdea("Go outside", 1);

	Cat	Patenron = Ronron;

	std::cout<< "Patenron first ideas 0: "<<Patenron.getIdea(0)<<"\n idea 1:"<<Patenron.getIdea(1)<<std::endl;
	Patenron.setIdea("This floor look like a nice litter", 0);
	Patenron.setIdea("its nap time", 1);
	std::cout<< "Patenron ideas after change 0: "<<Patenron.getIdea(0)<<"\nidea 1:"<<Patenron.getIdea(1)<<std::endl;
	std::cout<< "Ronron ideas after change 0: "<<Ronron.getIdea(0)<<"\nidea 1:"<<Ronron.getIdea(1)<<std::endl;

	return 0;
}
