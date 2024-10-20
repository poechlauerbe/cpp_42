#include "./Harl.hpp"
#include <iostream>

Harl::Harl() {}
Harl::~Harl() {}

void	Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}
void	Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now!" << std::endl;
}

void Harl::complain(std::string level)
{
	const std::string	statiArray[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*ptrToMemberFunc[])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	int length = sizeof(ptrToMemberFunc) / sizeof(ptrToMemberFunc[0]);
	int	i;

	for (i = 0; i < length; i++)
	{
		if (level == statiArray[i])
		{
			for (int j = i; j < length; j++)
				(this->*ptrToMemberFunc[j])();
			return;
		}
	}
	std::cerr << "Wrong input: '" << level << "'" << std::endl;

}