#include "RPN.hpp"

int	main(int argc, char* argv[]) {
	if (argc != 2)
		std::cout << "Need only 1 argument: was given ---> " << argc - 1 << std::endl;
	else {
		RPN a;

		int res = a.solving(argv[1]);
		std::cout << res << std::endl;
	}
}