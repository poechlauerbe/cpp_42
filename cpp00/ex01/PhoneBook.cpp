
#include "./PhoneBook.hpp"
#include "Contact.hpp"

void PhoneBook::add_contact(std::string first, std::string last, std::string nick, std::string number, std::string secret)
{
	for (int i = 6; i >= 0; i--)
	{
		_contacts[i].inc_index();
		_contacts[i + 1] = _contacts[i];
	}
	_contacts[0].add_contact(first, last, nick,  number, secret);
}

Contact	PhoneBook::get_contact(int index)
{
	return _contacts[index];
}

