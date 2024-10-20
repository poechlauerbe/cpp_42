#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

#include <string>

class PhoneBook
{
	private:
		Contact _contacts[8];

	public:
		void	add_contact(std::string first, std::string last, std::string nick, std::string number, std::string secret);
		Contact	get_contact(int index);
		void	ft_search(PhoneBook *phonebook);
};

#endif
