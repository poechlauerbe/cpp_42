#include <fstream>
#include <ios>
#include <iostream>
#include <ostream>
#include <streambuf>
#include <string>

int	checkLength(std::string str)
{
	if (str.length() < 1)
	{
		std::cerr << "filename or s1 to short - needs to be at least one char" << std::endl;
		return 1;
	}
	return 0;
}

int checkFilename(std::string str)
{
	int i = 0;
	int count = 0;

	while (str[i])
	{
		count++;
		if (str[i] == '.' || str[i] == '/')
			count = 0;
		i++;
	}
	if (count)
		return 0;
	std::cerr << "Filename check failed!" << std::endl;
	return 1;
}

int	readInfile(std::string filename, std::streamsize *size, char **buffer)
{
	std::filebuf	*readBuffer;

	std::ifstream infile(filename.c_str());
	if (!infile.is_open())
	{
		std::cerr << "Open of " << filename << " failed" << std::endl;
		return 1;
	}
	readBuffer = infile.rdbuf();
	*size = readBuffer->pubseekoff(0, infile.end, infile.in);
	readBuffer->pubseekpos (0,infile.in);

	*buffer = new char[*size + 1]();
	if (!*buffer)
	{
		std::cerr << "Allocation failed" << std::endl;
		infile.close();
		return 1;
	}
	readBuffer->sgetn(*buffer, *size);
	infile.close();
	return 0;
}

void	manipulateString(std::string *input, std::string s1, std::string s2)
{
	int			s1_len;
	int			s2_len;
	std::size_t	pos = 0;

	s1_len = s1.length();
	s2_len = s2.length();
	pos = input->find(s1, pos);
	while (pos != std::string::npos)
	{
		input->erase(pos, s1_len);
		input->insert(pos, s2);
		pos += s2_len;
		pos = input->find(s1, pos);
	}
}

int	createOutfile(std::string filename, std::string solution)
{

	filename += ".replace";
	std::ofstream outfile(filename.c_str());
	if (!outfile.is_open())
	{
		std::cerr << "Open of " << filename << " failed" << std::endl;
		return 1;
	}
	outfile.write(solution.c_str(), solution.length());
	outfile.close();
	return 0;
}

int openAndWrite(std::string filename, std::string s1, std::string s2)
{
	std::streamsize	size = 0;
	char			*buffer = NULL;

	if (readInfile(filename, &size, &buffer))
		return 1;
	std::string solutionString(buffer, size);
	delete[] buffer;
	manipulateString(&solutionString, s1, s2);
	if (createOutfile(filename, solutionString))
		return 1;
	return 0;
}

int main(int argc, char **argv)
{
	std::string	filename;
	std::string	s1;
	std::string	s2;

	if (argc != 4)
	{
		std::cerr << "Wrong number of arguments!" << std::endl;
		return 1;
	}
	filename = argv[1];
	if (checkLength(filename) || checkFilename(filename))
		return 1;
	s1 = argv[2];
	if (checkLength(s1))
		return 1;
	s2 = argv[3];
	if (openAndWrite(filename, s1, s2))
		return 1;
	return 0;
}
