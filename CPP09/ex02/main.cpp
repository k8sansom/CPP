#include "PmergeMe.hpp"
#include <iomanip>

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error. Usage: ./PmergeMe <positive integers>" << std::endl;
		return 1;
	}

	std::vector<int> unsortedVec;
	for (int i = 1; i < ac; i++)
	{
		int nbr = std::atoi(argv[i]);
		if (nbr < 0)
		{
			std::cerr << "Error" << std::endl;
			return 1;
		}
		unsortedVec.push_back(nbr);
	}
	PmergeMe<std::vector<int>, std::vector<Ints>> mergedVec;
	mergedVec.startTime();
	mergedVec.computeInput(unsortedVec);
	mergedVec.endTime();
	mergedVec.printMerge(mergedVec);
		std::cout << "Time to process a range of " << merge.getSize() << " elements with std::vector : ";
		std::cout << std::fixed << std::setprecision(1) << merge.getTime() << " us" << std::endl;
	}

	{
		std::list<int> unsortedLst;
		for (int i = 1; i < argc; i++)
		{
			int nbr = std::atoi(argv[i]);
			if (nbr < 0)
			{
				std::cerr << "Error" << std::endl;
				return 1;
			}
			unsortedLst.push_back(nbr);
		}

		PmergeMe<std::list<int>, std::list<Ints> > merge;
		merge.startTime();
		merge.computeInput(unsortedLst);
		merge.endTime();
		std::cout << "Time to process a range of " << merge.getSize() << " elements with std::list : ";
		std::cout << std::fixed << std::setprecision(1) << merge.getTime() << " us" << std::endl;
	}
	return 0;
}
