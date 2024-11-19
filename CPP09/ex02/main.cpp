#include "PmergeMe.hpp"
#include <sstream>

template <typename C>
void parseInput(C &input, int ac, char **av) {
    for (int i = 1; i < ac; ++i) {
        std::istringstream ss(av[i]);
        int num;
        ss >> num;
        input.push_back(num);
    }
}

int main(int ac, char **av) {
	std::srand(std::time(0));
    if (ac < 2) {
        std::cerr << "Error: Please provide a sequence of integers.\n";
        return 1;
    }
    std::vector<int> inputVector;
    std::list<int> inputList;

    parseInput(inputVector, ac, av);
    parseInput(inputList, ac, av);

	//process vector
    PmergeMe<std::vector<int>, std::vector<Ints>> pmergeVector;
    pmergeVector.computeInput(inputVector);

    std::cout << "Before: ";
    for (std::vector<int>::const_iterator it = inputVector.begin(); it != inputVector.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << "After: ";
    for (std::vector<int>::const_iterator it = pmergeVector.getSorted().begin(); it != pmergeVector.getSorted().end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << "Time to process a range of " << pmergeVector.getSize() << " elements with std::vector: " << pmergeVector.getTime() << " us\n";

	//process list
    PmergeMe<std::list<int>, std::list<Ints>> pmergeList;
    pmergeList.computeInput(inputList);
    std::cout << "Before: ";
    for (std::list<int>::const_iterator it = inputList.begin(); it != inputList.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << "After: ";
    for (std::list<int>::const_iterator it = pmergeList.getSorted().begin(); it != pmergeList.getSorted().end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << "Time to process a range of " << pmergeList.getSize() << " elements with std::list: " << pmergeList.getTime() << " us\n";

    return 0;
}
