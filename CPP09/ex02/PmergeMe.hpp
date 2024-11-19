#ifndef	PMERGEME_HPP
#define	PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <algorithm> 
#include <cmath>
#include <utility>

template <typename C, typename P>
class PmergeMe {
public:
    // Constructor, Destructor, and Assignment
    PmergeMe();
    ~PmergeMe();
    PmergeMe(PmergeMe const &copy);
    PmergeMe& operator=(PmergeMe const &src);

    // Public methods
    void	computeInput(C &input);
    C		getInput() const;
    C		getSorted() const;
    int		getSize() const;
	void 	printMerged() const;

    // Timing methods
    void	startTime();
    void	endTime();
    double	getTime() const;

private:
    // Member variables
    clock_t _start;
    clock_t _end;
    C		_input;
    C		_sorted;

    // Private methods
    P 		    _createPairs() const;
    static bool	_comparePairs(const std::pair<int, int> &pairOne, const std::pair<int, int> &pairTwo);
    static void _sort(std::vector<std::pair<int, int> > &pairs, bool (*comp)(const std::pair<int, int>&, const std::pair<int, int>&));
    static void _sort(std::list<std::pair<int, int> > &pairs, bool (*comp)(const std::pair<int, int>&, const std::pair<int, int>&));
    void	    _searchInsert(C &chain, int val, int end);
};

#endif
