#include "PmergeMe.hpp"
#include <cstdlib>
#include <iomanip> 

int main(int ac, char **av) {
	if (ac < 2) {
		std::cerr << "Error. Usage: ./PmergeMe <positive integers>" << std::endl;
		return 1;
	}

	// Parse input and validate
    	std::vector<int> inputValues;
    	for (int i = 1; i < ac; ++i) {
        	int nbr = std::atoi(av[i]);
        	if (nbr < 0) {
            		std::cerr << "Error: All numbers must be positive integers." << std::endl;
            		return 1;
        	}
        	inputValues.push_back(nbr);
   	}
	//sort and print for vector
	PmergeMe<std::vector<int>, std::vector<Ints>> mergedVec;
	mergedVec.startTime();
	mergedVec.computeInput(inputValues);
	mergedVec.endTime();
	mergedVec.printMerged();
	std::cout << "Time to process a range of " << mergedVec.getSize() << " elements with std::vector : ";
	std::cout << std::fixed << std::setprecision(1) << mergedVec.getTime() << " us" << std::endl;

	//sort and print for list
	std::list<int> inputList(inputValues.begin(), inputValues.end());
	PmergeMe<std::list<int>, std::list<Ints> > mergedList;
	mergedList.startTime();
	mergedList.computeInput(inputList);
	mergedList.endTime();
	std::cout << "Time to process a range of " << mergedList.getSize() << " elements with std::list : ";
	std::cout << std::fixed << std::setprecision(1) << mergedList.getTime() << " us" << std::endl;
	return 0;
}
