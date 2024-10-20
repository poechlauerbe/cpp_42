
#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
class Contact
{
	private:
		int			_index;
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_num;
		std::string _deep_secret;

	public:
		int			contact_exists();
		void		add_contact(std::string first, std::string last, std::string nick, std::string number, std::string secret);
		void		inc_index();
		int			get_index();
		std::string	get_firstname();
		std::string	get_lastname();
		std::string	get_nickname();
		std::string	get_number();
		std::string get_secrect();

};

#endif
