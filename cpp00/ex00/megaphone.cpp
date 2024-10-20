#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char **argv) {
	std::string	arg;
	char		temp;

	if (argc == 1) {
		std::cerr << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 1;
	}
	for (int i = 1; i < argc; i++)
	{
		arg = argv[i];
		for (int j = 0; j < (int) arg.length(); j++)
		{
			temp = toupper(arg[j]);
			std::cout << temp;
		}
	}
	std::cout << std::endl;
	return 0;
}
