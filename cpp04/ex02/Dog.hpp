#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain* _brain;
	public:
		Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		~Dog();

		void		setIdea(const std::string newIdea, unsigned int ideaNr);
		std::string	getIdea(unsigned int ideaNr) const;

		virtual void makeSound() const;
};

#endif
