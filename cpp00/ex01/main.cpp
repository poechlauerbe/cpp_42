
#include "./PhoneBook.hpp"
#include "./Contact.hpp"

#include <cctype>
#include <string>
#include <iostream>
#include <cstdlib>

void	msg_exit()
{
	std::cout << "\nExit...\n";
	exit(0);
}

void	num_check(std::string *number)
{
	int len = 0;
	int	err = 1;

	while (err)
	{
		std::getline(std::cin, *number);
		if (std::cin.eof())
			msg_exit();
		len = number->length();
		if (len > 0)
			err = 0;
		for (int i = 0; i < len; i++)
		{
			if (number[0][i] < '0' || number[0][i] > '9')
			{
				err = 1;
				break;
			}
			else
				err += 0;
		}
		if (err)
			std::cout << "Try again: ";
	}
}

bool	string_printable(std::string str, int len)
{
	for (int i = 0; i < len; i++)
	{
		if(!isprint(str[i]))
			return false;
	}
	return true;
}

void	input_loop(std::string *str)
{
	int	err = 1;
	int	len = 0;

	while (err)
	{
		std::getline(std::cin, *str);
		if (std::cin.eof())
			msg_exit();
		len = str->length();
		if (len >= 1 && str[0][0] != ' ')
			err = 0;
		if (!string_printable(*str, len))
			err = 1;
		if (err)
		 	std::cout << "Try again: ";
	}
}

void	ft_add(PhoneBook *phonebook)
{
	std::string	first;
	std::string	last;
	std::string	nick;
	std::string	number;
	std::string	secret;

	std::cout << "Add contact's first name: ";
	input_loop(&first);
	std::cout << "Add contact's last name: ";
	input_loop(&last);
	std::cout << "Add contact's nickname: ";
	input_loop(&nick);
	std::cout << "Add contact's hidden secret: ";
	input_loop(&secret);
	std::cout << "Add contact's number: ";
	num_check(&number);
	phonebook->add_contact(first, last, nick, number, secret);
	std::cout << "\n";
}

std::string	short_print(std::string word)
{

	int	len;

	len = word.length();
	if (len == 10)
		return word;
	else if (len < 10)
	{
		for (int i = 0; i < 10 - len; i++)
		{
			word.insert(0, " ");
		}
		return word;
	}
	else
	{
		word.erase(word.begin()+9, word.end());
		word += ".";
		return word;
	}
}

void	ft_print_4cols(PhoneBook *phonebook)
{
	Contact contact;
	std::cout << "\n     index|first name| last name|  nickname\n";
	for (int i = 0; i < 8; i++)
	{
		contact = phonebook->get_contact(i);
		if (!contact.contact_exists())
			break;
		std::cout << "         " << contact.get_index() << "|";
		std::cout << short_print(contact.get_firstname()) << "|";
		std::cout << short_print(contact.get_lastname()) << "|";
		std::cout << short_print(contact.get_nickname()) << "\n";
	}
	std::cout << "\n";
}

void	ft_search(PhoneBook *phonebook)
{
	std::string	index;

	ft_print_4cols(phonebook);
	std::cout << "\nWhich contact do you want to see in detail - use index: ";
	std::getline(std::cin, index);
	std::cout << "\n";
	if (std::cin.eof())
		msg_exit();
	if (index.length() != 1 || index[0] < '0' || index[0] > '7'|| !phonebook->get_contact(index[0] - '0').contact_exists())
		std::cout << "Wrong input!\n";
	else
	{
		std::cout << phonebook->get_contact(index[0] - '0').get_firstname() << "\n" ;
		std::cout << phonebook->get_contact(index[0] - '0').get_lastname() << "\n" ;
		std::cout << phonebook->get_contact(index[0] - '0').get_nickname() << "\n" ;
		std::cout << phonebook->get_contact(index[0] - '0').get_number() << "\n" ;
		std::cout << phonebook->get_contact(index[0] - '0').get_secrect() << "\n" ;
		std::cout << "\n";
	}
}

int	main()
{
	PhoneBook phonebook;
	std::string	command;

	while (true)
	{
		std::cout << "Hello, what do you want to do? (ADD, SEARCH or EXIT): ";
		std::getline(std::cin, command);
		if (command == "EXIT" || std::cin.eof())
		{
			std::cout << "\nExit...\n";
			return (0);
		}
		else if (command == "SEARCH")
			ft_search(&phonebook);
		else if (command == "ADD")
		 	ft_add(&phonebook);
	}
}

// check subject - if possible to just do first in first out - increment the index
// contact exists ev nicht notwendig
// check öäü
// while(true) // check if allowed
// check else if is allowed
