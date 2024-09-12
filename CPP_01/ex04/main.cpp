#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
    if (argc != 4)
		return (1 && std::cout << "Need arguments 3, was givven--->" << argc - 1 <<std::endl);
	size_t		pos = 0;
	std::string	name = argv[1];
	std::string	line;

	std::ifstream	inFile(argv[1]);
	if (!inFile)
		return(1 && std::cout << "Cant open file "<< std::endl);
	std::ofstream outFile(name + ".replace");
	while(getline(inFile, line))
	{
			while ((pos = line.find(argv[2], pos)) != std::string::npos && argv[2][0] != '\0')
			{
					line.erase(pos, strlen(argv[2]));
					line.insert(pos, argv[3]);
					pos += strlen(argv[3]);
			}
			outFile << line << std::endl;
			pos = 0;
	} 
	return (0);
}
