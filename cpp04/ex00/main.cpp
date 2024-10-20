#include <iostream>

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "Tests 1:\n" << std::endl;

	const Animal* meta = new Animal();
	if (!meta)
		return 1;
	const Animal* j = new Dog();
	if (!j)
		return (delete(meta), 1);
	const Animal* i = new Cat();
	if (!i)
		return (delete(j), delete(meta), 1);

	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << "\nDestructors 2:" << std::endl;
	delete(i);
	delete(j);
	delete(meta);

	std::cout << "\nTests 2:" << std::endl;

	const WrongAnimal* wmeta = new WrongAnimal;
	if (!wmeta)
		return 1;
	const WrongAnimal* wcat = new WrongCat;
	if (!wcat)
		return (delete wmeta, 1);
	const WrongCat wcat2;

	std::cout << wmeta->getType() << std::endl;
	wmeta->makeSound();
	std::cout << wcat->getType() << std::endl;
	wcat->makeSound();
	std::cout << wcat2.getType() << std::endl;
	wcat2.makeSound();

	std::cout << "\nDestructors 2:" << std::endl;
	delete wmeta;
	delete wcat;
}