#include "PmergeMe.hpp"
#include <cctype>
#include <cstddef>
#include <deque>

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe&) {}
PmergeMe& PmergeMe::operator=(const PmergeMe&) {return (*this);}
PmergeMe::~PmergeMe() {}

static bool chekcOverflow(char  *line)
{
	if (std::strlen(line) > 11)
		return (true);
	long	nbr = std::atol(line);
	return (nbr > INT_MAX || nbr < INT_MIN);
}

static void check_digit(std::string av){
	for (size_t i = 0; i < av.length(); i++) {
		if (!std::isdigit(av[i]))
			exit(1 && (std::cout << "Error: invalid input\n"));
	}
}

void PmergeMe::print(int ac, char **av){
	std::vector<int> 	arr;
	std::string			line;

	for (int i = 1; i < ac; ++i) {
		line = av[i];
		if (line.find(" ") != std::string::npos) {
			std::cout << "Error: input shouldn't contain spaces\n";
			exit(1);
		}
		if (chekcOverflow(av[i])) {
			std::cout  << "Error: overflow " << av[i] << "\n";
			exit(1);
		}
		check_digit(av[i]);
        int num = std::atoi(av[i]);
        if (num <= 0)
        {
            std::cout << "Error: invalid input\n";
            return ;   
        }
        arr.push_back(num);
    }
	std::vector<int>	vector_arr(arr.begin(),arr.end());
	std::cout << "Before: ";
	display(vector_arr);
	clock_t start_time = clock();
	fordJohnsonSort(vector_arr);
	clock_t end_time = clock();
	double  vector_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
	std::cout << "After: ";
	std::deque<int> deque_arr(arr.begin(), arr.end());
	start_time = clock();
	fordJohnsonSort(deque_arr);
	end_time = clock();
	display(deque_arr);
	double  deque_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
    std::cout << "Time to process with vector container: " << std::fixed << std::setprecision(5) << vector_time << " seconds\n";
    std::cout << "Time to process with deque container:  " << std::fixed << std::setprecision(5) << deque_time << " seconds\n";

}
