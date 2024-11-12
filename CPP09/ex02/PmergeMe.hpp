#ifndef	PMERGEME_HPP
#define	PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <algorithm>  

struct IntPair
{
	int one;
	int two;
};

template <typename Con, typename Pairs>

class PmergeMe {
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(PmergeMe const &copy);
		PmergeMe& operator=(PmergeMe const &src);

		void	computeInpute(Con& input);
		Con		getInput();
		Con		getSorted();
		int		getSize();
		void	startTime();
		void	stopTime();
		double	getTime();
	
	private:
		clock_t	_start;
		clock_t	_end;
		Con		_input;
		Con		_sorted;

		Pairs		_createPairs();
		static bool	_sortPairs(IntPair const pairOne, IntPair const pairTwo);
		static void	_sort(std::vector<IntPair>& pairs);
		static void	_sort(std::list<IntPair>& pairs);
		void		_searchInsert(Container &chain, int val, int end);
};

#endif