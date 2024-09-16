#include "ScalarConverter.hpp"

int main(int argc, char** argv) {

	if (argc == 2)
	{
		std::string conv(argv[1]);
		ScalarConverter::convert(conv);
	}
	else
		std::cerr << "Need 1 parameter, was given --> " << argc - 1 << std::endl;
	return (0);
}