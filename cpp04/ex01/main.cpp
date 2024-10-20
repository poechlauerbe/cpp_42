#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "Test1:" << std::endl;

	{
		const Animal* meta = new Animal();
		if (!meta)
			return 1;

		const Animal* j = new Dog();
		if (!j)
			return (delete(meta), 1);

		Animal* i = new Cat();
		if (!i)
			return (delete(j), delete(meta), 1);

		std::cout << "\nTest functions 1:" << std::endl;
		std::cout << j->getType() << std::endl;
		std::cout << i->getType() << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		std::cout << "\nDestructor 1:" << std::endl;
		delete(i);
		delete(j);
		delete(meta);
	}

	{
		std::cout << "\nTest2:" << std::endl;
		int		num = 5;
		Animal*	animals[num];

		for (int i = 0; i < num; i++) {
			if (i % 2)
				animals[i] = new Cat;
			else
				animals[i] = new Dog;
			if (!animals[i]) {
				num = i;
				break;
			}
		}
		for (int i = 0; i < num; i++) {
			animals[i]->makeSound();
		}
		for (int i = 0; i < num; i++) {
			delete animals[i];
		}


	}

	{
		std::cout << "\nTest deep copy Cat:\n" << std::endl;
		Cat	originalCat;
		Cat copyCat(originalCat);
		originalCat.setIdea("I want to get a beer", 34);
		Cat copyCat2 = originalCat;

		std::cout << "\nTest deep copy Cat1:\n" << std::endl;
		std::cout << "CopyCat idea (Copied before change): " << copyCat.getIdea(34) << std::endl;
		std::cout << "OriginalCat idea: " << originalCat.getIdea(34) << std::endl;
		std::cout << "CopyCat2 idea (Copied after change): " << copyCat2.getIdea(34) << std::endl;

		std::cout << "\nTest deep copyCat2:\n" << std::endl;
		copyCat.setIdea("This is another idea.", 34);
		std::cout << "CopyCat idea (Copied before change): " << copyCat.getIdea(34) << std::endl;
		std::cout << "OriginalCat idea: " << originalCat.getIdea(34) << std::endl;
		std::cout << "CopyCat2 idea (Copied after change): " << copyCat2.getIdea(34) << std::endl;
		originalCat.makeSound();
		copyCat.makeSound();
		copyCat2.makeSound();
		std::cout << originalCat.getIdea(100) << std::endl;

		std::cout << "\nConstructors and Destructors:" << std::endl;
	}

	{
		std::cout << "Test deep copy Dog:\n" << std::endl;
		Dog	originalDog;
		Dog copyDog(originalDog);
		originalDog.setIdea("I want to get a beer", 34);
		Dog copyDog2 = originalDog;

		std::cout << "\nTest Dog deep copy Dog1:\n" << std::endl;
		std::cout << "CopyDog idea (Copied before change): " << copyDog.getIdea(34) << std::endl;
		std::cout << "OriginalDog idea: " << originalDog.getIdea(34) << std::endl;
		std::cout << "CopyDog2 idea (Copied after change): " << copyDog2.getIdea(34) << std::endl;

		std::cout << "\nTest deep copy Dog2:\n" << std::endl;
		copyDog.setIdea("This is another idea.", 34);
		std::cout << "CopyDog idea (Copied before change): " << copyDog.getIdea(34) << std::endl;
		std::cout << "OriginalDog idea: " << originalDog.getIdea(34) << std::endl;
		std::cout << "CopyDog2 idea (Copied after change): " << copyDog2.getIdea(34) << std::endl;
		originalDog.makeSound();
		copyDog.makeSound();
		copyDog2.makeSound();
		std::cout << originalDog.getIdea(100) << std::endl;

		std::cout << "\nConstructors and Destructors:" << std::endl;
	}

	{
		std::cout << "\nanother deep copy test:" << std::endl;
		Dog basic;
		{
			Dog tmp = basic;
			// tmp = basic; // delete "= basic" above
		}
		std::cout << basic.getIdea(17) << std::endl;
	}

	{
		std::cout << "\nLast Test: (prep next exercise)" << std::endl;
		Animal testanimal;
		testanimal.makeSound();
	}

}
