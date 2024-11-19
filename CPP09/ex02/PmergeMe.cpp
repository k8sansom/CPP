#include "PmergeMe.hpp"

template <typename C, typename P>
PmergeMe<C, P>::PmergeMe() {}

template <typename C, typename P>
PmergeMe<C, P>::~PmergeMe() {}

template <typename C, typename P>
PmergeMe<C, P>::PmergeMe(PmergeMe const &copy): _input(copy._input), _sorted(copy._sorted) {}

template <typename C, typename P>
PmergeMe<C, P>& PmergeMe<C, P>::operator=(PmergeMe const &src) {
	if (this != &src) {
		_input = src._input;
		_sorted = src._sorted;
	}
	return *this;
}

template <typename C, typename P>
void PmergeMe<C, P>::computeInput(C &input) {
    _input = input;
    _sorted.clear();

    P pairs = _createPairs();
    _sort(pairs, _comparePairs);

    _sorted.push_back(pairs.begin()->second);
    for (typename P::iterator it = pairs.begin(); it != pairs.end(); ++it)
        _sorted.push_back(it->first);

    size_t curPower = 2;
    size_t jacobsthal[2] = {1, 3};
    while (jacobsthal[0] < pairs.size()) {
        size_t startIndex = std::min(jacobsthal[1], pairs.size());
        size_t endIndex = jacobsthal[0];
        for (size_t j = startIndex; j > endIndex; j--) {
            if (j - 1 < pairs.size()) {
				size_t endRange = std::min(static_cast<std::size_t>(pow(2.0, curPower) - 1), _sorted.size() - 1);
				typename P::iterator current = pairs.begin();
				std::advance(current, j - 1);
                _searchInsert(_sorted, current->second, endRange);
            }
        }

        size_t nextJacobsthal = jacobsthal[0] * 2 + jacobsthal[1];
        jacobsthal[0] = jacobsthal[1];
        jacobsthal[1] = nextJacobsthal;
        ++curPower;
    }

    if (_input.size() % 2)
        _searchInsert(_sorted, _input.back(), _sorted.size());
}

template <typename C, typename P>
C		PmergeMe<C, P>::getInput() const{
	return _input;
}

template <typename C, typename P>
C		PmergeMe<C, P>::getSorted() const{
	return _sorted;
}

template <typename C, typename P>
int		PmergeMe<C, P>::getSize() const{
	return _input.size();
}

template <typename C, typename P>
void PmergeMe<C, P>::startTime() {
    _start = clock();
}

template <typename C, typename P>
void PmergeMe<C, P>::endTime() {
    _end = clock();
}

template <typename C, typename P>
double PmergeMe<C, P>::getTime() const {
    return static_cast<double>(_end - _start) / CLOCKS_PER_SEC * 1e6; // Time in microseconds
}

template <typename C, typename P>
P PmergeMe<C, P>::_createPairs() const {
    P pairs;
    typename C::const_iterator it = _input.begin();
    typename C::const_iterator nextIt = it;
    std::advance(nextIt, 1);

    while (it != _input.end() && nextIt != _input.end()) {
        pairs.push_back(std::make_pair(std::max(*it, *nextIt), std::min(*it, *nextIt)));
        std::advance(it, 2);
        std::advance(nextIt, 2);
    }
    return pairs;
}

template <typename C, typename P>
bool PmergeMe<C, P>::_comparePairs(const std::pair<int, int> &pairOne, const std::pair<int, int> &pairTwo) {
    return pairOne.first <= pairTwo.first;
}

template <typename C, typename P>
void PmergeMe<C, P>::_sort(std::vector<std::pair<int, int> > &pairs, bool (*comp)(const std::pair<int, int>&, const std::pair<int, int>&)) {
    std::sort(pairs.begin(), pairs.end(), comp);
}

template <typename C, typename P>
void PmergeMe<C, P>::_sort(std::list<std::pair<int, int> > &pairs, bool (*comp)(const std::pair<int, int>&, const std::pair<int, int>&)) {
    pairs.sort(comp);
}

template <typename C, typename P>
void PmergeMe<C, P>::_searchInsert(C &chain, int val, int end) {
    typename C::iterator low = chain.begin();
    typename C::iterator high = chain.begin();
    std::advance(high, end);

    while (low != high) {
        typename C::iterator mid = low;
        std::advance(mid, std::distance(low, high) / 2);

        if (val < *mid) {
            high = mid;
        } else {
            low = mid;
            ++low;
        }
    }
    chain.insert(low, val);
}

template <typename C, typename P>
void PmergeMe<C, P>::printMerged() const {
	//print the input before sorting
	std::cout << "Before:\t\t";
	for (typename C::const_iterator it = _input.begin(); it != _input.end(); ++it) {
		std::cout << std::fixed << *it << " ";
	}
	std::cout << std::endl;
	
	//print the sorted output
	std::cout << "After:\t\t";
	for (typename C::const_iterator it = _sorted.begin(); it != _sorted.end(); ++it) {
		std::cout << std::fixed << *it << " ";
	}
	std::cout << std::endl;
}

template class PmergeMe<std::vector<int>, std::vector<std::pair<int, int> > >;
template class PmergeMe<std::list<int>, std::list<std::pair<int, int> > >;
