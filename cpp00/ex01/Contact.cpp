
#include "./Contact.hpp"
#include <string>

void	Contact::inc_index()
{
	_index++;
}

int		Contact::contact_exists()
{
	if (_first_name[0])
		return (1);
	return (0);
}


void	Contact::add_contact(std::string first, std::string last, std::string nick, std::string number, std::string secret)
{
	_index = 0;
	_first_name = first;
	_last_name = last;
	_nickname = nick;
	_phone_num = number;
	_deep_secret = secret;
}

int	Contact::get_index()
{
	return _index;
}

std::string	Contact::get_firstname()
{
	return _first_name;
}

std::string	Contact::get_lastname()
{
	return _last_name;
}

std::string	Contact::get_nickname()
{
	return _nickname;
}

std::string	Contact::get_number()
{
	return _phone_num;
}

std::string Contact::get_secrect()
{
	return _deep_secret;
}
