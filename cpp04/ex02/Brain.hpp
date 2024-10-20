#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {
	private:
		std::string	_ideas[100];

	public:
		Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
		~Brain();

		void	setIdea(const std::string newIdea, unsigned int ideaNr);
		std::string	getIdea(unsigned int ideaNr) const;
};

#endif
