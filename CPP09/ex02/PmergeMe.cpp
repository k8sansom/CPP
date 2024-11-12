#include "PmergeMe.hpp"
template <typename Con, typename Pairs>
PmergeMe<Con, Pairs>::PmergeMe() {}

template <typename Con, typename Pairs>
PmergeMe<Con, Pairs>::~PmergeMe() {}

template <typename Con, typename Pairs>
PmergeMe<Con, Pairs>::PmergeMe(PmergeMe const &copy): _input(copy._input), _before(copy._before), _after(copy._after) {}

template <typename Con, typename Pairs>
PmergeMe<Con, Pairs>& PmergeMe<Con, Pairs>::operator=(PmergeMe const &src) {
	if (this != &src) {
		_input = src._input;
		_before = src._before;
		_after = src._after;
	}
	return *this;
}

template <typename Con, typename Pairs>
void	PmergeMe<Con, Pairs>::computeInpute(Con& input) {
	_input = input;
	size_t contSize = _input.size();
	Pairs pairs = _createPairs();
	_sort(pairs);

	_sorted.clear();
	_sorted.push_back(pairs.begin()->second);
	for (typename Pairs::iterator it = pairs.begin(); it != pairs.end(); ++it)
		_sorted.push_back(it->first); 
	//need more here
}

template <typename Con, typename Pairs>
Con		PmergeMe<Con, Pairs>::getInput() {
	return _input;
}

template <typename Con, typename Pairs>
Con		PmergeMe<Con, Pairs>::getSorted() {
	return _sorted;
}

template <typename Con, typename Pairs>
int		PmergeMe<Con, Pairs>::getSize() {
	return _input.size();
}

template <typename Con, typename Pairs>
void	PmergeMe<Con, Pairs>::startTime() {
	_start = clock();
}

template <typename Con, typename Pairs>
void	PmergeMe<Con, Pairs>::stopTime() {
	_end = clock();
}

template <typename Con, typename Pairs>
double	PmergeMe<Con, Pairs>::getTime() {
	return (_end - _start) * 1e6 / CLOCKS_PER_SEC;
}
	
	private:
		clock_t	_before;
		clock_t	_after;
		Con		_input;
		Con		_sorted;

		Pairs		_createPairs();
		static bool	_sortPairs(IntPair const pairOne, IntPair const pairTwo);
		static void	_sortVector(std::vector<IntPair>& pairs);
		static void	_sortList(std::list<IntPair>& pairs);
		void		_searchInsert(Container &chain, int val, int end);