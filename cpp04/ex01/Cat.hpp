#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat  : public Animal {
	private:
		Brain* _brain;

	public:
		Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		~Cat();

		void	setIdea(const std::string newIdea, unsigned int ideaNr);
		
		std::string	getIdea(unsigned int ideaNr) const;

		void makeSound() const;
};

#endif
