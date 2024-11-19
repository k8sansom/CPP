#ifndef	PMERGEME_HPP
#define	PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <algorithm> 
#include <cmath>

struct Ints {
	int	first;
	int	second;
};

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
    P 			_createPairs() const;
    static bool	_comparePairs(Ints const &pairOne, Ints const &pairTwo);
    static void _sort(std::vector<Ints> &pairs, bool (*comp)(const Ints, const Ints));
    static void _sort(std::list<Ints> &pairs, bool (*comp)(const Ints, const Ints));
    void		_searchInsert(C &chain, int val, int end);
};

#endif